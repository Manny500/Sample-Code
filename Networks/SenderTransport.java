//Imports
import java.util.*;
import java.io.*;

/**
 * A class which represents the receiver transport layer
 */
public class SenderTransport{

    //Instance Variables
    private NetworkLayer nl;
    private Timeline tl;
    private int windowSize; //Window size
    private int increment; //Increment for timer
    private int base; //the current base number for window
    private int checksum; //checksum for pkt
    private int nextseqnum; //next sequence number to send
    private int sampleRTT;
    private int estimatedRTT;
    private int devRTT;
    private int lastSeen;
    private int countDuplicate;
    private boolean usingTCP;
    private HashMap<Integer, String> map = new HashMap<Integer, String>(); //simulated window
    private Queue<Message> buffer = new LinkedList<Message>(); //keep buffered msg in order
    private Packet pkt;

    //Constructor
    public SenderTransport(NetworkLayer nl){

        this.nl = nl;

        initialize();

    }//end of constructor

////////////////////////////////////////////////METHODS/////////////////////////////////////////////////////////////
    
    /**
     * This routine will be called once, before any of your other sender routines are called. 
     * It can be used to do any required initialization.
     */
    public void initialize(){

        this.base = 1;
        this.nextseqnum = 1;
        this.checksum = 0;
        this.increment = 0;
        this.countDuplicate = 0;
        this.lastSeen = 0;
    
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
     * Where message contains data to be sent to the B-side. 
     * This routine will be called whenever the upper layer at the sending side has a message to send. 
     * It is the job of your protocol to insure that the data in such a message is delivered in-order, 
     * and correctly, to the receiving side upper layer.
     * @param msg is the Message we need to send
     */
    public void sendMessage(Message msg){

        //get bytes from msg
        byte[] array = msg.getMessage().getBytes(); //DO WE NEED THIS IN TCP?
         
        /**
         * Calculate the time out for GBN and TCP
         * EstimatedRTT = (1- α)*EstimatedRTT + α*SampleRTT
         * α = 0.125
         * DevRTT = (1-β)*DevRTT + β*|SampleRTT-EstimatedRTT|
         * β = 0.25
         * TimeoutInterval = EstimatedRTT + 4*DevRTT
         */
        this.sampleRTT = (int)(2 * this.windowSize * tl.getTimeBetweenSends());
        this.estimatedRTT = (int)((1 - 0.125) * this.estimatedRTT + 0.125 * this.sampleRTT);
        this.devRTT = (int)((1-0.25) * devRTT + 0.25 * Math.abs(this.sampleRTT - this.estimatedRTT));
        this.increment = (int)(this.estimatedRTT + 4 * this.devRTT);
        
        //TCP 
        if(usingTCP){

            //Set a base, determine how many pkt we can send,window size
            if (map.size() < windowSize){

                //calculate the checksum
                this.checksum = this.getChecksum(msg.getMessage(), this.nextseqnum, this.nextseqnum);

                //Create the pkt, same ack as sequence
                pkt = new Packet(msg, this.nextseqnum, this.nextseqnum, checksum);

                //put the sent pkt in our map until we get an ack for it
                if(!map.containsKey(this.nextseqnum)){

                    //Need to save it as string so corruption doesnt occur
                    String plzNoCorruption = msg.getMessage();

                    //put the sent pkt in our map until we get an ack for it
                    map.put(this.nextseqnum, plzNoCorruption);

                    if(NetworkSimulator.DEBUG > 2){

                        System.out.println("ADDING to map: " + this.nextseqnum);
                    }
                }

                //This method will always send pkt to the receiver aka B-side
                nl.sendPacket(pkt, 1);

                //start timer for oldest ack
                if (this.base == this.nextseqnum){

                    //start timer
                    tl.startTimer(this.increment);
                }

                //increase the sequence number
                this.nextseqnum++;

            }else{

                if(NetworkSimulator.DEBUG > 2){

                    System.out.println("Buffering msg, window is FULL");
                }

                //add it to a buffer for future sending
                this.buffer.add(msg);

            }//END of TCP

        //Go-Back-N
        }else{ 

            //Set a base, determine how many pkt we can send,window size
            if (map.size() < windowSize){

                //calculate the checksum
                this.checksum = this.getChecksum(msg.getMessage(), this.nextseqnum, this.nextseqnum);

                //Create the pkt, same ack as sequence
                pkt = new Packet(msg, this.nextseqnum, this.nextseqnum, checksum);

                //put the sent pkt in our map until we get an ack for it
                if(!map.containsKey(this.nextseqnum)){
                    
                    //Need to save it as string so corruption doesnt occur
                    String plzNoCorruption = msg.getMessage();

                    //put the sent pkt in our map until we get an ack for it
                    map.put(this.nextseqnum, plzNoCorruption);

                    if(NetworkSimulator.DEBUG > 2){

                        System.out.println("ADDING to map: " + this.nextseqnum);
                    }
                }

                //This method will always send pkt to the receiver aka B-side
                nl.sendPacket(pkt, 1);

                //start timer for oldest ack
                if (this.base == this.nextseqnum){

                    //start timer
                    tl.startTimer(this.increment);
                }

                //increase the sequence number
                this.nextseqnum++;

            }else{

                if(NetworkSimulator.DEBUG > 2){

                    System.out.println("Buffering msg, window is FULL");
                }

                //add it to a buffer for future sending
                this.buffer.add(msg);
            }
        }
    
    }// end of method
    
    /**
     * Where packet is a structure of type pkt. 
     * This routine will be called whenever a packet sent from the receiver arrives at the sender.
     * pkt is the (possibly corrupted) packet sent from the receiver.
     */
    public void receiveMessage(Packet pkt){
    
        //check for corruption
        if(this.getChecksum(pkt.getMessage().getMessage(), pkt.getAcknum(), pkt.getSeqnum()) != pkt.getChecksum()){

            //pkt is corrupted do nothing wait for time out
            if(NetworkSimulator.DEBUG > 2){

                System.out.println("Sorry pkt from receiver is corrupted " + pkt.getAcknum());
            }

            return;
        }

        this.lastSeen = pkt.getAcknum();

        // TCP
        if(usingTCP){

            //should be the first in the window
            this.base = pkt.getAcknum() + 1;

            if(NetworkSimulator.DEBUG > 2){

                    System.out.println("GOT: " + pkt.getAcknum() + " " + map.containsKey(pkt.getAcknum()) + " " + map.size());
                }

            //if it is the first in the window
            if(this.base == this.nextseqnum){

                Iterator it = map.entrySet().iterator();

                //Remove from window all pkt that have been aked, cummulative acks too
                while(it.hasNext()){

                    Map.Entry pair = (Map.Entry)it.next();
                    
                    int sequence = (int)pair.getKey();

                    //Remove all pkt with seq = or < than current ack #
                    if(sequence <= pkt.getAcknum()){

                        it.remove();

                        if(NetworkSimulator.DEBUG > 2){

                            System.out.println("Removing map: " + sequence);
                        }
                    }

                }

                //if there is new space in the window then send buffered msg
                while((buffer.peek() != null) && (map.size() < windowSize)){

                    sendMessage(buffer.poll());
                }

                //reset timer every time we get ack
                tl.stopTimer();
                tl.startTimer(this.increment);

            }else if(map.containsKey(pkt.getAcknum())){

                Iterator it = map.entrySet().iterator();

                //Remove from window all pkt that have been aked, cummulative acks too
                while(it.hasNext()){

                    Map.Entry pair = (Map.Entry)it.next();
                    
                    int sequence = (int)pair.getKey();

                    //Remove all pkt with seq = or < than current ack #
                    if(sequence <= pkt.getAcknum()){

                        it.remove();

                        if(NetworkSimulator.DEBUG > 2){

                            System.out.println("Removing map: " + sequence);
                        }
                    }

                }

                //if there is new space in the window then send buffered msg
                while((buffer.peek() != null) && (map.size() < windowSize)){

                    sendMessage(buffer.poll());
                }

                //reset timer every time we get ack
                tl.stopTimer();
                tl.startTimer(this.increment);

            }else{

                //Check for the need of fast retransmit
                if(pkt.getAcknum() == this.lastSeen){

                    //IF we see 3 duplicate acks
                    if(countDuplicate == 3){

                        this.fastRetransmit();

                    }else{

                        this.countDuplicate++;
                    }
                }

                if(NetworkSimulator.DEBUG > 2){

                    System.out.println("seqnum != to " + "base: " + this.base + " next seq: " + this.nextseqnum);
                    System.out.println("wait for timeout and count the duplicated acks " + countDuplicate);
                }

            }//End of TCP

        // Go-Back-N
        }else{ 

            //should be the first in the window
            this.base = pkt.getAcknum() + 1;

            if(NetworkSimulator.DEBUG > 2){

                    System.out.println("GOT: " + pkt.getAcknum() + " " + map.containsKey(pkt.getAcknum()) + " " + map.size());
                }

            //if it is the first in the window
            if(this.base == this.nextseqnum){

                Iterator it = map.entrySet().iterator();

                //Remove from window all pkt that have been aked, cummulative acks too
                while(it.hasNext()){

                    Map.Entry pair = (Map.Entry)it.next();
                    
                    int sequence = (int)pair.getKey();

                    //Remove all pkt with seq = or < than current ack #
                    if(sequence <= pkt.getAcknum()){

                        it.remove();

                        if(NetworkSimulator.DEBUG > 2){

                            System.out.println("REmoving map: " + sequence);
                        }
                    }

                }

                //if there is new space in the window then send buffered msg
                while((buffer.peek() != null) && (map.size() < windowSize)){

                	sendMessage(buffer.poll());
                }

                //reset timer every time we get ack
                tl.stopTimer();
                tl.startTimer(this.increment);

            }else if(map.containsKey(pkt.getAcknum())){

                Iterator it = map.entrySet().iterator();

                //Remove from window all pkt that have been aked, cummulative acks too
                while(it.hasNext()){

                    Map.Entry pair = (Map.Entry)it.next();
                    
                    int sequence = (int)pair.getKey();

                    //Remove all pkt with seq = or < than current ack #
                    if(sequence <= pkt.getAcknum()){

                        it.remove();

                        if(NetworkSimulator.DEBUG > 2){

                            System.out.println("REmoving map: " + sequence);
                        }
                    }

                }

                //if there is new space in the window then send buffered msg
                while((buffer.peek() != null) && (map.size() < windowSize)){

                    sendMessage(buffer.poll());
                }

                //reset timer every time we get ack
                tl.stopTimer();
                tl.startTimer(this.increment);

            }else{

                if(NetworkSimulator.DEBUG > 2){

                    System.out.println("seqnum != to base " + "base: " + this.base + "next seq: " + this.nextseqnum);
                    System.out.println("wait for timeout");
                }
            }

        }

    }// end of method

    /**
     * This routine will be called when the sender receives 3 duplicated acks
     */
    public void fastRetransmit(){

        if(NetworkSimulator.DEBUG > 2){

            System.out.println("In fastRetransmit");
        }

        int min = -1;
        for (Integer key : map.keySet()){

        	if(min == -1 || min > key){

				min = key;

			}
        }

        //send the lowest seqnum in window
        this.sendMessage(new Message(map.get(min)));

    }//end of method
    
    /**
     * This routine will be called when the sender's timer expires (thus generating a timer interrupt).
     * You'll probably want to use this routine to control the retransmission of packets. 
     * See starttimer()and stoptimer() below for how the timer is started and stopped.
     */
    public void timerExpired(){

        //TCP
        if(usingTCP){

            //Get smallest seq number not acked
            int smallestSeq = Integer.MAX_VALUE;

            //get iterator from set
            Iterator iter = this.map.entrySet().iterator();

            //Resend smallest pkt in window
            while(iter.hasNext()){

                Map.Entry entry = (Map.Entry)iter.next();

                //Get smalles unacked seqnum from the window
                if((int)entry.getKey() < smallestSeq){

                    smallestSeq = (int)entry.getKey();            
                }

            }

            if(map.containsKey(smallestSeq)){

                if(NetworkSimulator.DEBUG > 2){

                    System.out.println("Resending pkt: " + smallestSeq);
                    System.out.println("base: " + this.base);

                }

                //create the message
                Message m = new Message ((String)map.get(smallestSeq));
                
                //calculate the checksum
                this.checksum = this.getChecksum(m.getMessage(), smallestSeq, smallestSeq);

                //Create the pkt, same ack as sequence
                pkt = new Packet(m, smallestSeq, smallestSeq, this.checksum);

                //This method will always send pkt to the receiver aka B-side
                nl.sendPacket(pkt, 1);

                //Start the timer, if we have more data to send
                if(map.size() > 0){

                    tl.startTimer(this.increment);
                }

            }

        //Go-Back-N
        }else{ 

            //syncronice sequence #'s
            this.nextseqnum = this.base;

            //get iterator from set
        	Iterator iter = this.map.entrySet().iterator();

            //Resend all pkts in window
        	while(iter.hasNext()){

        		Map.Entry entry = (Map.Entry)iter.next();

                if(NetworkSimulator.DEBUG > 2){

                    System.out.println("base: " + this.base);
                    System.out.println("sequence pkt: " + this.nextseqnum);
                    System.out.println("Resending pkt: " + entry.getKey());
        		
                }

                //create the message
                Message m = new Message ((String)entry.getValue());
                
                //calculate the checksum
                this.checksum = this.getChecksum(m.getMessage(), (int)entry.getKey(), (int)entry.getKey());

                //Create the pkt, same ack as sequence
                pkt = new Packet(m, (int)entry.getKey(), (int)entry.getKey(), this.checksum);

                //This method will always send pkt to the receiver aka B-side
                nl.sendPacket(pkt, 1);

        	}

            //Start the timer, if we have more data to send
            if(map.size() > 0){

                tl.startTimer(this.increment);
            }

        }//End of GBN
    
    }// end of method
    
    /**
     * Set the timeline to the specified time line below
     * @param tl the new timeline
     */
    public void setTimeLine(Timeline tline){
    
        this.tl = tline;

    }// end of method
    
    /**
     * This method will set the window size for TCP and Go-Back-n
     * @param n is the size 
     */
    public void setWindowSize(int n){
    
        this.windowSize = n;

    }// end of method
    
    /**
     * Sets the protocol whether it be Go-Back-n or TCP
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