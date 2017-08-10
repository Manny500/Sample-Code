//Imports
import java.util.*;

/**
 * A class which represents the receiver transport layer
 */
public class ReceiverTransport{

    //Instance Variables
    private ArrayList<Integer> buffer = new ArrayList<Integer>();
    private ReceiverApplication ra;
    private NetworkLayer nl;
    private boolean usingTCP;
    private int expectedSeqNum;
    private int lastAcked;
    private int checksum;

    //Constructor
    public ReceiverTransport(NetworkLayer nl){

        ra = new ReceiverApplication();
        this.nl=nl;
        initialize();

    }// end of method

////////////////////////////////////////////////METHODS/////////////////////////////////////////////////////////////

    /**
     * This routine will be called once, before any of your other receiver routines are called.
     * It can be used to do any required initialization.
     */
    public void initialize(){

        expectedSeqNum = 1;
        lastAcked = 0;
        this.checksum = 0;
    
    }// end of method

    /**
     * This routine will calculate the pkt checksum
     * Using the msg, seqnum, and acknum
     * @param msg is message in pkt
     * @param seqnum sequence number in pkt
     * @param acknum ack number in pkt
     * @return int the calculated checksum
     */
    public int getChecksum(String msg, int seqnum, int acknum){

        //Set an temp sum
        int tempCheckSum = 0;

        //convert msg to array char
        char[] string = msg.toCharArray();

        for(int x = 0; x < string.length; x++){

            //give each char a int value and add to sum
            tempCheckSum += (int)string[x];
        }

        //add sequence and ack to sum
        tempCheckSum = tempCheckSum + seqnum + acknum;

        //return the sum
        return tempCheckSum;
    
    }// end of method
    
    /**
     * This routine will be called whenever a packet sent from the sender arrives at the receiver.
     * packet is the (possibly corrupted) packet sent from the sender.
     * @param Packet pkt from sender
     */
    public void receiveMessage(Packet pkt){

        //check for corruptions
        if(this.getChecksum(pkt.getMessage().getMessage(), pkt.getAcknum(), pkt.getSeqnum()) != pkt.getChecksum()){

            //pkt is corrupted must do nothing.
            if(NetworkSimulator.DEBUG > 2){

                System.out.println("Sorry msg is from sender is corrupted");
            }

            return;
        }

        if(NetworkSimulator.DEBUG > 2){

            //unpack the pkt...ReceiverApplication
            ra.receiveMessage(pkt.getMessage()); //prints out the message
        }   

        //make the message
        Message msg = new Message("ACK");
        byte[] array = msg.getMessage().getBytes();

        // TCP
        if(usingTCP){

            if(this.expectedSeqNum == pkt.getSeqnum() ){

                //get last acked from out of order pkts
                if(buffer.size() > 0){

                    //System.out.println("Getting MY FRIEDS");

                    int temp = this.expectedSeqNum;
                    int end = 0;

                    for(int x = 0; x < buffer.size(); x++){

                       // System.out.println("BUFFER C: " + buffer.get(x) + ", " + temp);

                        if((buffer.get(x) > temp) && (buffer.get(x) == temp + 1)){

                            temp = buffer.get(x);

                            end = x;
                            //System.out.println("MY FRIEDS");

                        }
                    }

                    buffer.subList(0, end).clear();

                    if(temp == this.expectedSeqNum){

                        //make the reply pkt
                        pkt = new Packet(msg, this.expectedSeqNum, pkt.getSeqnum(), this.getChecksum(msg.getMessage(), this.expectedSeqNum, pkt.getSeqnum()));

                        //send the ack
                        nl.sendPacket(pkt, 0);

                        //update last acked
                        this.lastAcked = this.expectedSeqNum;

                        //increase the expected sequence number
                        this.expectedSeqNum++;


                    }else{

                        this.lastAcked = temp;

                        //make the reply pkt
                        pkt = new Packet(msg, this.lastAcked, this.lastAcked, this.getChecksum(msg.getMessage(), this.lastAcked, this.lastAcked));

                        //send the ack
                        nl.sendPacket(pkt, 0);

                        //update expecting number 
                        this.expectedSeqNum = temp + 1;

                    }

                }else{

                    //make the reply pkt
                    pkt = new Packet(msg, this.expectedSeqNum, pkt.getSeqnum(), this.getChecksum(msg.getMessage(), this.expectedSeqNum, pkt.getSeqnum()));

                    //send the ack
                    nl.sendPacket(pkt, 0);

                    //update last acked
                    this.lastAcked = this.expectedSeqNum;

                    //increase the expected sequence number
                    this.expectedSeqNum++;
                }

            }else{

                //buffer out of order packet
                buffer.add(pkt.getSeqnum());

                //System.out.println("BUFFER SIZE " + buffer.size());

                //keep the buffer sorted
                Collections.sort(buffer);

                //send reply ack of last acked 
                pkt = new Packet(msg, this.expectedSeqNum, this.lastAcked, this.getChecksum(msg.getMessage(), this.expectedSeqNum, this.lastAcked));

                //send the ack
                nl.sendPacket(pkt, 0);

            }

        // Go-Back-N
        }else{ 

            if(this.expectedSeqNum == pkt.getSeqnum() ){

                //make the reply pkt
                pkt = new Packet(msg, this.expectedSeqNum, pkt.getSeqnum(), this.getChecksum(msg.getMessage(), this.expectedSeqNum, pkt.getSeqnum()));

                //send the ack
                nl.sendPacket(pkt, 0);

                //update last acked
                this.lastAcked = this.expectedSeqNum;

                //increase the expected sequence number
                this.expectedSeqNum++;

            }else{

                //make the reply pkt
                pkt = new Packet(msg, this.expectedSeqNum, this.lastAcked, this.getChecksum(msg.getMessage(), this.expectedSeqNum, this.lastAcked));

                //send the ack
                nl.sendPacket(pkt, 0);
            }

        }//End of GBN
       
    }// end of method
    
    /**
     * Sets teh protocol whether it be Go-Back-n or TCP
     * TCP = 1
     * Go-Back-n = 0
     * @param int n sets TCP or Go-Back-n
     */
    public void setProtocol(int n){
    
        if(n > 0){

            usingTCP = true;

        }else{

            usingTCP = false;
        }

    }//end of method

}//end of class