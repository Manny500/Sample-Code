//Imports
import java.util.*;

/**
 * This class represents the timeline of events in a priority queue
 */
public class Timeline{

    //Instance Variables
    private PriorityQueue<Event> events; //timeline of events. 
    private int timeBetweenSends; //Avg. time between two packets being sent
    private int totalMessagesToSend; //total number of messages to send
    private int sentSoFar; //number of messages sent so far 
    private int timeSoFar; // time which has passed so far
    private Random ran; //random number generator
    private int lastArrivalTime;  //last arrival time so far
    private Event timerPointer; //pointer to currently running timer
    
    /**
     * A constructor to initialize variables.
     */
    public Timeline(int time, int numOfMessages){
    
        events = new PriorityQueue<Event>(); // sort/compare events based on their time
        timeBetweenSends = time;
        totalMessagesToSend = numOfMessages;
        ran = new Random();
        timeSoFar = 0;
        sentSoFar = 1; //set to one because we send the first packet right away
        lastArrivalTime = 0;
        createSendEvent(); //bengin first packet, sort of a black one
        timerPointer = null;

    }//end of constructor

////////////////////////////////////////////////METHODS/////////////////////////////////////////////////////////////

    /**
     * Getting next event. 
     * If it is a send event, and there are still messages that need to be sent, sending the next one.
     */
    public Event returnNextEvent(){
    
        //Retrieves and removes the next event of this queue
        Event tmp = events.poll();

        //Check if there is an event
        if(tmp == null){

            return tmp;
        }

        //Get the current time, also updates the time
        timeSoFar = tmp.getTime();    

        //Check if the event is a send event and whether we still have events to send
        if(tmp.getType() == Event.MESSAGESEND && sentSoFar < totalMessagesToSend){
        
            createSendEvent(); //add new event to queue
            sentSoFar++;
        }

        return tmp;

    }//end of method

    /**
     * Will allow an incoming pkt to determine its sequence number
     * @return int number fo messages sent so far 
     */
    public int getSeqNum(){

        return (sentSoFar - 2); //should be this plus number of bytesß

    }//end of method

    /**
     * Will allow an incoming pkt to determine its avg time between sends
     * @return int //Avg. time between two packets being sent
     */
    public int getTimeBetweenSends(){

        return timeBetweenSends;

    }//end of method

    /**
     * Will allow an incoming pkt to determine its ack number
     * @return int number fo messages sent so far 
     */
    public int getAckNum(){

        return (sentSoFar - 2);

    }//end of method

    /**
     * Will
     * @return int
     */
    public int getTimeSoFar(){

        return this.timeSoFar;

    }//end of method
    
    /**
     * Creating a send event.First generating a random number using the exponential distribution with
     * average timeBetweenSends and then adding the event.
     */
    public void createSendEvent(){
    
        //get random decimal number
        double tmp = ran.nextFloat();

        //if tmp is 0 then choose 0.00001 else stick to original
        tmp = (tmp == 0) ? 0.00001 : tmp;

        //Get the average RTT
        int time = (int)(timeBetweenSends * (-Math.log(tmp)) + timeSoFar);

        if(NetworkSimulator.DEBUG > 2){

            System.out.println("'createSendEvent'-Inserting future arrive event at " + timeSoFar + " with avg RTT time: " + time );
        }

        //Insert new event into the queue, from sender
        events.add(new Event(time, Event.MESSAGESEND, Event.SENDER));

    }//end of method

    /**
     * Creating an arrive event. This first checks for the last arrival time (since packets cannot be reordered), 
     * and the adds a random number uniformly distributed from 1-9
     * to calculate the time of the arrival event. It then adds the event to the queue.
     * @param pkt packet that will arrive
     * @param to who are we sending the packet to
     */
    public void createArriveEvent(Packet pkt, int to){
    
        lastArrivalTime = (lastArrivalTime > timeSoFar) ? lastArrivalTime : timeSoFar; //if lastArrivalTime > timeSoFar then lastArrived else timeSoFar
        lastArrivalTime = 1 + (int)(ran.nextFloat() * 9) + lastArrivalTime;

        if(NetworkSimulator.DEBUG > 2){

            String tmp = (to == Event.SENDER) ? "Sender" : "Receiver"; //check if its from sender or receiver
            System.out.println("'createArriveEvent'-Inserting future arrive event at " + timeSoFar + " with calculated avg RTT: " + lastArrivalTime + " to: " + tmp);
        }

        //Insert new arrive event into the queue, from specified host and specified pkt
        events.add(new Event(lastArrivalTime, Event.MESSAGEARRIVE, to, pkt));

    }//end of method
    
    /**
     * Starting timer, If it is already started it prints out an error message. Setting timerPointer to point at timer event.
     * @param increment timeout for timer
     */
    public void startTimer(int increment){
    
        //check if timer is already on
        if(timerPointer != null){
        
            //System.out.println("Timer is allready on!");
            return;
        }

        //create the new timer pointer
        timerPointer = new Event(timeSoFar + increment, Event.TIMER, Event.SENDER);
        events.add(timerPointer);

        if(NetworkSimulator.DEBUG > 2){

            System.out.println("startTimer'-Inserting future timer event at time: " + timeSoFar + " plus increment = " +  increment);
        }

    }//end of method

    /**
     * Kills timer and sets timerPointer to null
     */
    public void stopTimer(){

        //check if timer is already on
        if(timerPointer == null){

            //System.out.println("Timer is not on!");
            return;
        }     
        
        timerPointer.killTimer();
        timerPointer = null;

    }//end of method

}//end of class