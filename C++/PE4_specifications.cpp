PROGRAM SPECIFICATION:
Note: Don't use global variables and use a beginner friendly codes.
This program has two parts: queue implementation and queue application. You are to
implement the queue first and then use that in implementing the program application.
Queue Implementation
Each cell of the queue should be able to hold two strings. To hold each string, create an array
of characters with big enough size.
The following are the expected operations for the queue:
• INIT(): creates and returns an empty queue
• EMPTY(Q): returns true if queue Q is empty, otherwise, returns false
• FRONT(Q): returns a copy of the front item of queue Q
• ENQUEUE(x, Q): inserts item x in queue Q
• DEQUEUE(Q): removes and returns the front item of queue Q

Queue Application
The following is the specification of the application you will implement using the queue you
have created. The application is about an order system in a fast-food chain, coffee shop, etc.
The order system has the following main menu:
Mcdonald's Menu:
[1] Fall in line
[2] Serve order
[3] Next order
[4] Closing time
[0] Exit
Enter choice:

Details of the menu items are as follows:
Fall in line: Once selected, the program should ask the user for the name of the person
falling in line and that person’s order.
Serve order: Once selected, the program should proceed with the process of serving the
order of the customer who is first in line. For this process, the customer info (name and order)
will be removed from the queue and the program displays a message with the following
format:
“Now serving [order] to customer [customer name].”
If the queue is empty, the program should not proceed with performing the process for the
menu and instead display the following message:
“The QUEUE is EMPTY. No orders to serve.”

Next order: Once selected, the program should display the order to be served next. The
program should display a message with the following format:
“Next order: [order] of customer [customer name].”
If the queue is empty, the program should not proceed with performing the process for the
menu and instead display the following message:
“The QUEUE is EMPTY. No order to serve.”
Closing time: Once selected, the program should proceed with the process of serving all the
orders left in the queue. For each order being served, display the same message from menu
item [2]. After serving the last order, the program should inform the user that all the orders
have been served.

If the queue is empty, the program should not proceed with performing the process for the
menu and instead display the following message:
“The QUEUE is EMPTY. No order to serve.”
Exit: Once selected, the program should terminate with a message informing the user that
the order system has been terminated.
Note: After processing the selected main menu item, the program should loop back to the
main menu. The program should end only when the user selects the main menu item Exit.