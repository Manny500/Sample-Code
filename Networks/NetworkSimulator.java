/**
 * @Author Manny Tenorio
 * @Author Conrad Stoerker
 */

//Imports
import java.util.*;
import java.io.FileReader;

/**
 * A class which runs the Network simulator 
 */
public class NetworkSimulator{

    //Instance Variables
    public static int DEBUG;

    /*
     * Main method with follwing variables
     * @param args[0] file with messages
     * @param args[1] time between messages
     * @param args[2] loss probability
     * @param args[3] corruption probability
     * @param args[4] window size
     * @param args[5] protocol type
     * @param args[6] Debug
     */
    public static void main(String[] args){

        //current event to process
        Event currentEvent;
        int finalTime = 0;
        final long startTime = System.nanoTime();

        //checking to see if enough arguements have been sent    
        if(args.length < 5){

            System.out.println("need at least 7 arguements");
            System.exit(1);
        }

        //Will do print statements...Must be set before any other instantiations
        DEBUG = Integer.parseInt(args[6]); // if more than 2 or 3 it will pring out debug messages | 0 for nothing 

        //reading in file line by line. Each line will be one message
        ArrayList<String> messageArray = readFile(args[0]);

        //creating a new timeline with an average time between packets.
        Timeline timeLine = new Timeline(Integer.parseInt(args[1]), messageArray.size()); //A class to reference time, adding first pkt

        //creating a new network layer with specific loss and corruption probability.
        NetworkLayer netLayer = new NetworkLayer(Float.parseFloat(args[2]),Float.parseFloat(args[3]),timeLine);

        //creating sender, with specific messages and network
        SenderApplication sendApp = new SenderApplication(messageArray,netLayer);

        //creating send tranport layer with current sender application transport
        SenderTransport sendTrans = sendApp.getSenderTransport();

        //sender and receiver transport needs access to timeline to set timer.
        sendTrans.setTimeLine(timeLine);

        //creates the receiver transport with current network
        ReceiverTransport receiveT = new ReceiverTransport(netLayer);

        //setting window size
        sendTrans.setWindowSize(Integer.parseInt(args[4]));

        //setting protocol type, GO-Back_n or TCP
        sendTrans.setProtocol(Integer.parseInt(args[5]));
        receiveT.setProtocol(Integer.parseInt(args[5]));

        //this loop will run while there are events in the priority queue
        while(true){

            //get next event
            currentEvent = timeLine.returnNextEvent(); //get 1st pkt and adding the next

            //if no event present, break out
            if(currentEvent == null){
                break;
            }

            //if event is time to send a message, call the send message function of the sender application.   
            if(currentEvent.getType() == Event.MESSAGESEND){
                
                if(DEBUG > 0){

                    System.out.println("YAY IN 1");  
                }

                sendApp.sendMessage();

                if(DEBUG > 0){
                    System.out.println("Message sent from sender to receiver at time " + currentEvent.getTime());   
                }

            }else if (currentEvent.getType() == Event.MESSAGEARRIVE){ //if event is a message arrival

                //if it arrives at the sender, call the get packet from the sender
                if(currentEvent.getHost() == Event.SENDER){
                      
                    if(DEBUG > 0){

                        System.out.println("YAY IN 2 AT Sender"); 
                        System.out.println("Message arriving from receiver to sender at time " + currentEvent.getTime()); 
                    }

                    sendTrans.receiveMessage(currentEvent.getPacket());
                      
                }else{ //if it arrives at the receiver, call the get packet from the receiver

                    if(DEBUG > 0){

                        System.out.println("YAY IN 3 AT RECEIVER"); 
                        System.out.println("Message arriving from sender to receiver at time " + currentEvent.getTime());
                    }

                    receiveT.receiveMessage(currentEvent.getPacket());
                }

            }else if (currentEvent.getType() == Event.TIMER){ //If event is timer type

                if(DEBUG > 0){

                    System.out.println("YAY IN 4 IM A TIMER"); 
                    System.out.println("Timer expired at time " + currentEvent.getTime());
                }

                if(timeLine.getTimeSoFar() > finalTime){
                    finalTime = timeLine.getTimeSoFar();
                }

                timeLine.stopTimer();
                sendTrans.timerExpired();

            }else if (currentEvent.getType() == Event.KILLEDTIMER){ 

                //do nothing, it is just a turned off timer.

                if(DEBUG > 0){

                    System.out.println("YAY IN 5 IM A TIMER"); 
                }

            }else{ //this should not happen.

                System.out.println("Unidentified event type!");
                System.exit(1);
            }

        } //end of while loop

        final long endTime = System.nanoTime();

        final long timeTaken = endTime - startTime;

        System.out.print(args[1]  + "," + args[2] + "," + args[3] + "," + args[4] + "," + args[5] + "," + finalTime + "," + timeTaken);

    } //end of main

////////////////////////////////////////////////METHODS/////////////////////////////////////////////////////////////

    /**
     * Will read a file line by line and store them in an arraylist
     * @param fileName is the name of the file to read
     * @return ArrayList< String> contains all the messages from the file
     */
    public static ArrayList<String> readFile(String fileName){

        ArrayList<String> messageArray = new ArrayList<String>();
        Scanner sc = null;

        try{

            sc = new Scanner(new FileReader(fileName));

        }catch(Exception e){

            System.out.println("Could not open file " + e);

        }

        //Each line in the file will be a packet/message
        while(sc.hasNextLine()){

            messageArray.add(sc.nextLine());

        }

        return messageArray;

    } //end of read file method

} //end of class