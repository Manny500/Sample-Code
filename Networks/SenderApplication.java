//Imports
import java.util.*;

/**
 * A class which represents the sender's application. the sendMessage will be called at random times.
 */
public class SenderApplication{

    //Instance Variables
    private SenderTransport st; //transport layer used
    private ArrayList<String> messages; //all messages the application will send
    private int index; //how many messages has the application sent so far
    private Timeline tl; //the timeline associated with the simulation
    
    //Constructor
    public SenderApplication(ArrayList<String> messages, NetworkLayer nl){
    
        st = new SenderTransport(nl);
        this.messages = messages;
        index = 0;    

    }//end of constructor

////////////////////////////////////////////////METHODS/////////////////////////////////////////////////////////////
        
    /**
     * Get the transport layer
     * @retun SenderTransport returns the transport layer
     */
    public SenderTransport getSenderTransport(){
    
        return st;

    }//end of method

    /**
     * Sends the message through the transport layer
     */   
    public void sendMessage(){
 
        st.sendMessage(new Message(messages.get(index++)));

    }//end of method
    
}//end of class