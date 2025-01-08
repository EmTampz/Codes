/**
 * This is the consumer thread for the bounded buffer problem.
 */

//package factory;

import java.util.*;

class Consumer implements Runnable
{
   public Consumer(Channel m) { 
      mbox = m;
   }
   
   public void run() {
   Date message;
   
     while (true)
      {
		//pause for 5 seconds
		SleepUtilities.nap();

         // CONSUME AN ITEM FROM THE BUFFER
         
         System.out.println("Consumer wants to consume.");
       	 
       	 //calls the receive function of MessageQueue, saves it in the message variable 
       	 message = (Date)mbox.receive();
       	 
       	 //prints an info, when message is not null, that consumer has consumed an item
		 if (message != null)
         	System.out.println("Consumer consumed " + message);
      }
   }
   
   private  Channel mbox;
}
