//Tampugao ,Mohammad Muraya
// The program show a list menu that ables to add, delete, and display elements on an array based.
#include <iostream>
using namespace std;

struct List 
{
    int* arry_list;
    int Lsize;
};

//function declarations
void ADT_append(List& lst);
void ADT_pop(List& lst);
void ADT_display(const List& lst);
void ADT_deleteList(List& lst);
int main() 
{
    List lst = { new int[10], 0 }; // Initialize the array with size 10
    int Select;
    int size; // Added variable for list size
    int val, newval; // Added variables for update

    while (true) 
    {
         cout << " " << endl;
        cout << "[List Menu]:\n1. [Add Item]\n2. [Delete Item]\n3. [Display List]\n4. [Delete List]\n5. [Exit]\n" << endl;
        cout << "Select:";

        cin >> Select; // input
        cout << endl;

        if (Select == 1) ADT_append(lst); // call the function for adding elements in various ways
        else if (Select == 2) ADT_pop(lst); // call the function for deleting the specific element
        else if (Select == 3) ADT_display(lst); // Call the function in showing the list
        else if (Select == 4) ADT_deleteList(lst); // Call the function for deleting the list
        else if (Select == 5) 
        {
            delete[] lst.arry_list; // Free allocated memory before exiting 
            exit(0);
        }
        else cout << "Try again!." << endl;
    }

    return 0;
}

void ADT_append(List& lst)
{
    //variable declaration
    int choice;
    int input;

    //Sub-menu
    cout << " " << endl;
    cout << "Where to add the item?" << endl;
    cout << "[1] Start of the list" << endl;
    cout << "[2] End of the list" << endl;
    cout << "[3] Specific position" << endl;
    cout << "[0] Cancel\n" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
        case 0:
            // Cancel
            break;

        case 1:  // This Add element to the Start of the List
            cout << "Please enter the item to be added: ";
            cin >> input;
            //  The loop shifts the elements to the right to make space for the new element
            for (int i = lst.Lsize; i > 0; i--)
            {
                lst.arry_list[i] = lst.arry_list[i - 1];
            }

            // Add the new item to the start
            lst.arry_list[0] = input;
            lst.Lsize++;

            cout << "Element added to the start of the list.\n" << endl;
            break;

        case 2:
            // This Add Item to the End of the List
            cout << "Please enter the element to be added: ";
            cin >> input;

            // Check if the list is full
            if (lst.Lsize >= 10)
            {
                cout << "The list is full!!!\n" << endl;
            }
            else
            {
                lst.arry_list[lst.Lsize] = input;
                lst.Lsize++;
                cout << "Element added at the end of the list.\n" << endl;
            }
            break;

        case 3:// This add Item to a Specific Position
            cout << "Please enter the element to be inserted: ";
            cin >> input;
            int position;

            cout << "Enter the specific position (1-" << lst.Lsize + 1 << ")  only: ";
            cin >> position;

            if (position < 1 || position > lst.Lsize + 1)
            {
            cout << "Invalid position.\n" << endl;
             position = lst.Lsize + 1;
            }
             else
            {
             // It Shift elements to the right to make space for the new element
            for (int i = lst.Lsize; i >= position - 1; i--)
            {
            lst.arry_list[i + 1] = lst.arry_list[i];
             }

        // This Add the new item to the specified position
        lst.arry_list[position - 1] = input;
        lst.Lsize++;
        cout << "Item added to position " << position << " of the list.\n" << endl;
    }
    break;

        default:
            cout << "Invalid choice.\n" << endl;
            break;
    }
}



void ADT_pop(List& lst)
{
    // Check if the list is empty
    if (!lst.Lsize) 
    {
        cout << "List is empty.\n" << endl;
        return;
    }

    int input_delete;
    
    cout << "Enter the element to delete: ";
    cin >> input_delete;

    int delete_index = -1;
    // Search for the index of the element to be deleted
    for (int i = 0; i < lst.Lsize; i++) 
    {
        if (*(lst.arry_list + i) == input_delete) 
        {
            delete_index = i;
            break;
        }
    }

    
    if (delete_index == -1) 
    {
        cout << "The list contains no such element\n" << endl;
        return;
    }

   
    cout << "The element " << input_delete << ", which is at position " << delete_index << ", has been deleted.\n" << endl;

    // Shift elements to fill the gap created by deleting the element
    for (int i = delete_index; i < lst.Lsize - 1; i++) 
    {
        *(lst.arry_list + i) = *(lst.arry_list + i + 1);
    }

    // Decrease the list size to reflect the deletion
    lst.Lsize--;

   
    cout << " The Element deleted successfully.\n" << endl;
}



void ADT_display(const List& lst) 
{
    // This checks if the list is empty
    if (lst.Lsize == 0) 
    {
        cout << "The list is empty.\n" << endl;
        return;
    }

    cout << "List elements and their positions:" << endl;
    // this loop through the list to show the elements and their positions
    for (int i = 0; i < lst.Lsize; i++) 
    {
        // Display the position and its corresponding element in the list
        cout << "[" << i + 1 << "] " << lst.arry_list[i] << endl;
    }
}



void ADT_deleteList(List& lst) 
{
    if (lst.arry_list) 
    {
        free(lst.arry_list); // Free the memory used by the list
        lst.arry_list = NULL; // Set the list pointer to NULL
        lst.Lsize = 0; // Reset the list size
        cout << "The list has been emptied!\n" << endl;
    }
    else 
    {
        cout << "List is already empty.\n" << endl;
    }
}
