//Imports

/**
 * A class whoch represents an application message (which is simply a string)
 */
public class Message{
    
    //Instance Variables
    private String x; //var for the message

    //Constructor
    public Message(String x){ 

        this.x = x;
    } 

////////////////////////////////////////////////METHODS/////////////////////////////////////////////////////////////

    /**
     * Will get the message
     * @return String is the message to get
     */
    public String getMessage(){

        return x;

    }//end of method
    
    /**
     * Will corrupt the message
     */
    public void corruptMessage(){

       x = String.valueOf(x.charAt(0)+1) + x.substring(1);

    }//end of method

}//end of class