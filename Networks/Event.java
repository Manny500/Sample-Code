//Imports

/**
 * A class which represents an event and is used in the Timeline class
 */
public class Event implements Comparable<Event>{


    //Instance Variables
    int time; //time of the event
    int type; //type of event
    int host; //host where event is happening
    Packet pkt; //pkt related to event if relevant (only arrive events)

    //Types of events
    public static int MESSAGESEND = 0;  
    public static int MESSAGEARRIVE = 1;
    public static int TIMER = 2;
    public static int KILLEDTIMER = 3;
    public static int SENDER = 0;
    public static int RECEIVER = 1;

    /**
     * Initializing new event without packet. This will be used for sending events
     * @param time time of event
     * @param type type of event
     * @param host where event is happening.
     */
    public Event(int time, int type, int host){

        this.time = time;
        this.type = type;
        this.host = host;

    }//end constructor

////////////////////////////////////////////////METHODS/////////////////////////////////////////////////////////////

    /**
     * Initializing new event with packet. This will be used for arriving events
     * @param time time of event
     * @param type type of event
     * @param host where event is happening.
     * @param pkt packet that is arriving.
     */
    public Event(int time, int type, int host, Packet pkt){

        this.time = time;
        this.type = type;
        this.host = host;
        this.pkt = pkt;

    }//end of method
    
    /**
     * Kills timer by simply setting its event type to KILLEDTIMER
     */
    public void killTimer(){ 

        if(type != TIMER){

            System.out.println("Trying to stop a timer on an event that is not a timer! should not happen!");
            System.exit(1);
        }

        type = KILLEDTIMER;

    }// end of method
    
    /**
     * Will return the time of the event 
     * @return int is the time of the event 
     */
    public int getTime(){

        return time;

    }// end of method
    
    /**
     * Will return the type of the event 
     * @return int is the type of the event
     */
    public int getType(){

        return type;

    }// end of method
    
    /**
     * Will return the host of the event 
     * @return int is the host of the event
     */
    public int getHost(){

        return host;

    }// end of method
    
    /**
     * Will return the packet of the event 
     * @return Packet is the packet of the event
     */
    public Packet getPacket(){

        return pkt;

    }// end of method
    
    /**
     * Compares the time of an event to the time of another event  
     * If the same the time will be the same 
     * @return int return the difference 
     */
    public int compareTo(Event e){

        return this.time - e.time;

    }//end of method

}//end of class 