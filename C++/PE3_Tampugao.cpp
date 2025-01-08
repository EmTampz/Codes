//Tampugao, Mohammad Muraya
//PE_3
//This program has two parts: stack implementation and stack application. It exhibits pop,push,etc. and be applied to the menu of washing process.
#include <iostream>
#include <string>

using namespace std;

// Node structure for the application of linked list
struct Node 
{
    string items_data;
    Node* next;
};

// Stack class used for the implementation of its operations
class Stack 
{
    private:
        Node* top;  // This is a Pointer to the top of the stack

    public:
        Stack() 
        {
            top = nullptr; // Initialization of the stack set to empty
        }


    // This function checks if the stack is empty
    bool S_Empty() 
    {
        return top == nullptr;
    }

    // This function checks if the stack is full however, the stack will never be full
    bool S_Full() 
    {
        return false;
    }

     // This function makes the stack empty
    void Empty_all() 
    {
        while (!S_Empty()) 
        {
            pop();
        }
    }

    // This function adds the item to the top of the stack.
    void push(string KW_item)  // item is the kitcheware to be added
        {
            Node* newNode = new Node; // declaration of pointer to the Node
            newNode->items_data = KW_item; //assigns the kitchenware data to the new node
            newNode->next = top; // this ppoints the new node at the top of stock
            top = newNode; // updating the top pointer to point to newNode.
        }

    // This function pops and  the top element and update it from the stack
    string pop() 
    {
        if (S_Empty()) //checks and calls the S_Empty method and nothing to pop
        {
            return "";
        }
        string KW_item = top->items_data; // this access the data member of the Node pointed by the top pointer and assign it to the item variable to be removed 
        Node* temp = top; //temporary pointer to assign in the top
        top = top->next; // updates the top pointer and point it to next node in the stack
        delete temp;// deallocate the previous top
        return KW_item;// kitchenware has been removed from the stack.
    }


    // This function return the top element of the stack
    string top_Element() 
    {
        if (S_Empty()) 
        {
            return "";
        }
        return top->items_data; //this retrieves the data stored in the top node of the stack.
    }  
};


int main() 
{
    Stack S;
    
    while (true) 
    {   //MENU
        cout << "\nKitchenware Washing Machine:" << endl;
        cout << "[1] Add kitchenware" << endl;
        cout << "[2] Wash kitchenware" << endl;
        cout << "[3] Top kitchenware" << endl;
        cout << "[4] Wash all" << endl;
        cout << "[0] Exit" << endl;
        cout << "\nEnter choice: ";
        
        int select;
        cin >> select;
        
        switch (select) 
        {
            case 1: // Add kitchenware
                if (!S.S_Full()) 
                {
                    string add_kitchenware;
                    cout << "\nEnter kitchenware to be washed: ";
                    cin >> add_kitchenware; // input of kitchenware

                    S.push(add_kitchenware); // this adds the kitchenware in the stack
                } 
                else 
                {
                    cout << "The STACK is FULL. Cannot add kitchenware.\n" << endl;
                }
                break;
                
            case 2: // Wash kitchenware
                if (!S.S_Empty()) 
                {
                    string washed_kitchenware = S.pop(); //declared variable assign the value of the pop kitchenware

                    cout << washed_kitchenware << " is being washed." << endl;
                } 
                else 
                {
                    cout << "The STACK is EMPTY. No more kitchenware to wash./n" << endl;
                }
                break;
                
            case 3: // Top kitchenware
                if (!S.S_Empty()) 
                {
                    cout << S.top_Element() << " is next to be washed.\n" << endl; //calls the top_element method to display the top of the stack
                }
                else 
                {
                    cout << "The STACK is EMPTY. No kitchenware to wash.\n" << endl;
                }
                break;
                
            case 4: // Wash all
                while (!S.S_Empty())  // this iterates and perform the statement while it's not yet empty through calling the empty method
                {
                    string washed_kitchenware = S.pop(); // calls the method pop and stores it in the washed_kitchenware

                    cout << washed_kitchenware << " is being washed.\n" << endl;
                }

                cout << "All kitchenware has been washed.\n" << endl;
                break;
                
            case 0: // Exit
                cout << "Gikapoy na ang washing machine.\n" << endl;
                return 0;
                
            default:
                cout << "Invalid. Select Again!!!\n" << endl;
        }
    }

    return 0;
}
