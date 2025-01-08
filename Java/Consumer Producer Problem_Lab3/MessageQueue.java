/**
 * This program implements the bounded buffer using message passing.
 * Note that this solutions is NOT thread-safe. A thread safe solution
 * can be developed using Java synchronization which is discussed in Chapter 6.
 */
//package factory;

import java.util.Vector;

public class MessageQueue implements Channel
{
    private Vector queue;
    
    // constructor which creates a vector to represent the buffer
    public MessageQueue() {
        queue = new Vector();
    }
    
    /*
     * This implements a non-blocking send. Used by the Producer class
     */
    public void send(Object item) {
        
        //adds an element at the back of the Vector
        queue.addElement(item);
    }
    
    /*
     * This implements a non-blocking receive. Used by the Consumer class
     */
    
    public Object receive() {
        
        //cannot delete if no item in the vector...queue.size() returns the number of elements in the vector
        if (queue.size() == 0)
            return null;
        else
            //returns the top of the vector and then deletes it
            return queue.remove(0);
    }
    
}
