//Imports
import java.util.*;

/**
 * A class which represents the transoprt layer for both sender and receiver.
 */
public class NetworkLayer{

    //Instance Varibles
    float lossProbability; //probablity of losing a packet
    float currProbability; //probability of curropting a packet
    Timeline tl; 
    Random ran; //random number generator for losing packets.

    //Constructor
    public NetworkLayer(float lp, float cp,Timeline tl){

        lossProbability = lp;
        currProbability = cp;
        this.tl = tl;
        ran = new Random();
    }

////////////////////////////////////////////////METHODS/////////////////////////////////////////////////////////////

    /**
     * Sending packet if it is not lost, and corrupting it if necessary.
     * @param pkt is the packet being sent
     * @param the id of the host to be sent to either 0 or 1
     */
    public void sendPacket(Packet pkt, int to){

        //Test if we have a loss, according to a random generator vs loss probability
        if(ran.nextDouble() < lossProbability){
        
            if(NetworkSimulator.DEBUG > 1){

                System.out.println("Packet seq: " + pkt.getSeqnum() + " ack: " + pkt.getAcknum() + " LOST");
            }

            return;    
        }

        //Test if we have a to corrupt the pkt, according to a random generator vs the corruption probability
        if(ran.nextDouble() < currProbability){
        
            if(NetworkSimulator.DEBUG > 1){

                System.out.println("Packet seq: " + pkt.getSeqnum() + " ack: " + pkt.getAcknum() + " CORRUPTED");
           }

           //If we must corrupt pkt, run corrupt method
            pkt.corrupt();
        }

        if(NetworkSimulator.DEBUG > 1){

            System.out.println("Packet seq: " + pkt.getSeqnum() + " ack: " + pkt.getAcknum() + " sent:)");
        }

        //Finally send the pkt to appropriate host
        tl.createArriveEvent(pkt, to);

    }//end of method

}//end of class