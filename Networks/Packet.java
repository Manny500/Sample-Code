//Imports
import java.util.*;

/**
 * A class which represents a packet
 */
public class Packet{
    
    //Instance Variables
    private Message msg; //the enclosed message
    private int seqnum; //packets seq. number
    private int acknum; //packet ack. number
    private int checksum; //packet checksum

    Random ran; //random number generator

    //Constructor
    public Packet(Message msg, int seqnum, int acknum, int checksum){

        this.msg = msg;
        this.seqnum = seqnum;
        this.acknum = acknum;
        this.checksum = checksum;
        this.ran = new Random();

    }// end of method
    
////////////////////////////////////////////////METHODS/////////////////////////////////////////////////////////////

    /**
     * Get the packert acknowledgement number
     * @return int is the acknowledgement number
     */
    public int getAcknum(){
    
        return acknum;

    }// end of method
    
    /**
     * Gets the packet sequence number
     * @return int is the sequence number
     */
    public int getSeqnum(){
    
        return seqnum;

    }// end of method
    
    /**
     * Gets the message in the packet
     * @return Message is the info on the packet
     */
    public Message getMessage(){
    
        return msg;

    }// end of method
    
    /**
     * Will sets the checksum field to have a valid value
     */
    public void setChecksum(){

        char[] string = this.msg.getMessage().toCharArray();

        for(int x = 0; x < string.length; x++){

            this.checksum += (int)string[x];
        }

        this.checksum = this.checksum + this.seqnum + this.acknum;
    
    }// end of method
    
    /**
     * Will return the pkt's checksum
     * @return int is the pkt's checksum
     */
    public int getChecksum(){

        return checksum;

    }//end of method
    
    /**
     * This method returns wheather the packet is corrupt
     * @retun boolean if the packet is corrupt
     */
    public boolean isCorrupt(){
    
        return false;

    }//end of method
    
    /**
     * This method corrupts the packet the follwing way:
     * corrupt the message with a 75% chance
     * corrupt the seqnum with 12.5% chance
     * corrupt the ackum with 12.5% chance
     */
    public void corrupt(){ 

        //Check whether to corrupt
        if(ran.nextDouble() < 0.75){

            this.msg.corruptMessage();

        }else if(ran.nextDouble() < 0.875){

            this.seqnum = this.seqnum + 1;

        }else{

            this.acknum = this.acknum + 1;
        }

    }//end of method
    
}//end of class