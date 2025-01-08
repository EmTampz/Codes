/**
 * This is the producer thread for the bounded buffer problem.
 */

//package factory;

import java.util.*;

class Producer implements Runnable
{
   public Producer(Channel m)
   {
      mbox = m;
   }              
   
   public void run()
   {
   Date message;
     
      while (true) { 
      	//pause for 5 seconds
		SleepUtilities.nap();   
			
		//PRODUCE AN ITEM
			
		//saves the current date/time into the message variable	
         message = new Date();      
		 System.out.println("Producer produced " + message);
		 
         // produce an item & enter it into the buffer
         mbox.send(message);
      }
   }
   
   private  Channel mbox;
}
