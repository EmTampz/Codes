//Tampugao,Mohammad Muraya
// This program demonstrates queue implementation, a linked-list based and be applied to a restaurants system of serving using queue operations.
#include <iostream>
#include <string>

using namespace std;
class Queue {
private:
    struct Node // structure Node represent the items that it will hold in the queue , each node contains a string named as name and order for the restaurant order system
    {
        string c_name;
        string order;
        Node* next; // pointer in the nxt node
    };

    Node* front; //pointer to the front of queue, pointing the first node.
    Node* tail; // pointer to the rare of queue, pointing the last node.

public:
    Queue()  // constructor of the class, setting the front and rare as NULL
    {
        front = nullptr;
        tail = nullptr;
    }

    bool empty()  // this function return true if the front pointer is null
    {
        return front == nullptr;
    }

    string head_Name()  //function that return the front node of the queue, accessing the string name
    {
        return front->c_name;;
    }

    string head_Order() //  retunr front node, accessing the order
    {
        return front->order;
    }


    void enqueue(string c_name, string order) // function to insert an item at the tail
    {
        Node* newNode = new Node; // allocation of memory for new node and set the pointer to newNode
        
       /*  this assign the parameter to the name/order member of the new node */
        newNode->c_name = c_name; 
        newNode->order = order;
        newNode->next = nullptr;  // this sets nxt pointer of new node to nullptr


        if (empty()) 
        { //pointers of front and tail are both set to the new node 
            front = newNode;
            tail = newNode;
        } 
        else 
        {//new node is linked to the node and updating the next pointer of the current tail node to point to the new node,  
           tail->next = newNode;
            tail = newNode;
        }
    }


    void dequeue()  ///This function removes the front node from the queue.
    {
        if (!empty()) 
            {
            Node* temp = front; // this creates a temporary pointer temp,  pointing to the front node.
            front = front->next; // updating the front pointer to the next node
            delete temp; // frees memory that was allcoated in previous first node
            }
    }
};

void INIT(Queue& customer_Qorder) 
{
    customer_Qorder = Queue(); // this creates a new class and assigns it to the customer_Qorder object.
}

bool EMPTY(Queue& customer_Qorder) 
{
    return customer_Qorder.empty(); //returns the result of the empty() 
}

// function where you can input the name and order of a customer
void fall_in_line(Queue& customer_Qorder) 
{
    string c_name, order;
    cout << "Customer's name: ";

    cin.ignore();// this clears extra character
    getline(cin, c_name); // this reads the input and stores it in the c_name
    cout << "Enter " << c_name << "'s order: ";
    getline(cin, order);//this reads the input and stores it in the order
    customer_Qorder.enqueue(c_name, order); // calling the customer_Qorder to put the name and order of customer in it.
}

// function that gives the customers their order
void serve_order(Queue& customer_Qorder)
{
    if (!customer_Qorder.empty()) 
        {
        cout << "Now serving '" << customer_Qorder.head_Order() << "' to customer '" << customer_Qorder.head_Name() << "'." << endl; // this call the customer_Qorder to get the name and order at the head
        customer_Qorder.dequeue(); // calling the method of  customer_Qorder to remove the customer after being served in the queue.
        }
    else 
        {
        cout << "The QUEUE is EMPTY. No orders to serve." << endl;
        }
}

void next_order(Queue& customer_Qorder)  // this function only display the next order in the queue without removing it
{
    if (!customer_Qorder.empty()) 
        {
        cout << "Next order: '" << customer_Qorder.head_Order() << "' of customer '" << customer_Qorder.head_Name() << "'." << endl; //calling the method of instance
        } 
    else 
        {
        cout << "The QUEUE is EMPTY. No order to serve." << endl;
        }
}

//this function serves all the remaining orders in the queue 

void closing_time(Queue& customer_Qorder) 
    {
     if (customer_Qorder.empty()) 
     {
        cout << "\nThe QUEUE is EMPTY. No orders to serve." << endl;
        return;
     }
    //while not empty yet, loops is use to navigate all the remaining orders by accessing the head and be served  or dequeue them
    while (!customer_Qorder.empty()) 
    {
        cout << "Now serving '" << customer_Qorder.head_Order() << "' to customer '" << customer_Qorder.head_Name() << "'." << endl;
        customer_Qorder.dequeue();
     }
    cout << "\nAll orders have been served." << endl;
} 

int main()
{
    Queue customer_Qorder; // isntance is set to manage the customer orders
    
    while (true) // loop to display the menu of the order system of the fastfood chain
    {
        cout << "\nMcDonald's Menu:" << endl;
        cout << "[1] Fall in line" << endl;
        cout << "[2] Serve order" << endl;
        cout << "[3] Next order" << endl;
        cout << "[4] Closing time" << endl;
        cout << "[0] Exit" << endl;
        cout << "Enter choice: ";
        
        int select; 
        cin >> select; // input from the menu 

        switch (select)  //use to choose among the order system
        {
            case 1:
                fall_in_line(customer_Qorder);
                break;
            case 2:
                serve_order(customer_Qorder);
                break;
            case 3:
                next_order(customer_Qorder);
                break;
            case 4:
                closing_time(customer_Qorder);
                break;
            case 0:
                cout << " Thank you for choosing McDonald's. System Terminated." << endl;
                return 0;
            default:
                cout << "Hey! 0-5 lang dapat." << endl;
        }
    }

    return 0;
}
