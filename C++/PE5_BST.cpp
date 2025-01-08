//Tampugao,Mohammad Muraya_Hufana, Phillip Ian John
//The program demonstrates a Binary Search tree, which allow to perform several operatuo
#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    int count;
    Node* left;
    Node* right;

    Node(int value) 
    {
        data = value;
        count = 1;
        left = right = nullptr;
    }
};

class BinaryTree 
{
private:
    Node* root;

    Node* insertRecursive(Node* node, int value) 
    {
        if (node == nullptr)
            return new Node(value);

        if (value == node->data) 
        {
            node->count++;
        } 
        else if (value > node->data) 
        {
            node->right = insertRecursive(node->right, value);
        }

        else 
        {
            node->left = insertRecursive(node->left, value);
        } 

        return node;
    }

    Node* findMin(Node* node) 
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* findMax(Node* node) 
    {
        while (node->right != nullptr)
            node = node->right;
        return node;
    }

    Node* deleteRecursive(Node* node, int value) 
    {
        if (node == nullptr)
            return node;

        if (value > node->data)
            node->right = deleteRecursive(node->right, value);
        else if (value < node->data)
            node->left = deleteRecursive(node->left, value);
        else 
        {
            if (node->count > 1)
            {
                node->count--;
            } 
            else 
            {
                Node* temp;

                 while (node != nullptr) 
                {
                    temp = node->right;
                    delete node;
                    node = temp;
                
                }
                return nullptr;
            }
        }
        return node;
    }


    Node* searchRecursive(Node* node, int value) 
    {
        if (node == nullptr || node->data == value)
            return node;

         if (value >= node->data)
            return searchRecursive(node->right, value);

        return searchRecursive(node->left, value);
    }

    

    Node* findSuccessor(Node* node, int value) 
    {
        Node* current = searchRecursive(root, value);
        if (current == nullptr) 
        {
            cout << "Item not found." << endl;
            return nullptr;
        }

        if (current->right != nullptr)
            return findMin(current->right);

        Node* successor = nullptr;
        Node* ancestor = root;

        while (ancestor != current) {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            } 
            else 
            {
                ancestor = ancestor->right;
            }
        }

        if (successor != nullptr)
            return successor;
        else 
        {
            cout << "No successor found." << endl;
            return nullptr;
        }
    }

    Node* findPredecessor(Node* node, int value) 
    {
        Node* current = searchRecursive(root, value);
        if (current == nullptr) 
        {
            cout << "Item not found." << endl;
            return nullptr;
        }

        if (current->left != nullptr)
            return findMax(current->left);

        Node* predecessor = nullptr;
        Node* ancestor = root;

        while (ancestor != current) {
            if (current->data > ancestor->data) 
            {

                predecessor = ancestor;
                ancestor = ancestor->right;
            } 
            else 
            {
                ancestor = ancestor->left;
            }
        }

        if (predecessor != nullptr)
            return predecessor;
        else 
        {
            cout << "No predecessor found." << endl;
            return nullptr;
        }
    }

    void displayPreOrder(Node* node) 
    {
        if (node != nullptr) 
        {
            cout << node->data << "(" << node->count << ") ";
            displayPreOrder(node->left);
            displayPreOrder(node->right);
        }
    }

    void displayInOrder(Node* node) 
    {
        if (node != nullptr) 
        {
            displayInOrder(node->left);
            cout << node->data << "(" << node->count << ") ";
            displayInOrder(node->right);
        }
    }

    void displayPostOrder(Node* node) 
    {
        if (node != nullptr) 
        {
            displayPostOrder(node->left);
            displayPostOrder(node->right);
            cout << node->data << "(" << node->count << ") ";
        }
    }

    public:
        BinaryTree() 
        {
            root = nullptr;
        }

        void insert(int value) 
        {
            root = insertRecursive(root, value);
            cout << "Item inserted successfully." << endl;
        }

        void remove(int value) 
        {
            root = deleteRecursive(root, value);
            cout << "Item removed successfully." << endl;
        }

        void search(int value) 
        {
            Node* result = searchRecursive(root, value);
            if (result != nullptr)
                cout << "Item found. Count: " << result->count << endl;
            else
                cout << "Item not found." << endl;
        }

        void findMax() 
        {
            if (root != nullptr) {
                Node* maxNode = findMax(root);
                cout << "Maximum item: " << maxNode->data << "(" << maxNode->count << ")" << endl;
            } 
            else {
                cout << "Tree is empty." << endl;
            }
        }

        void findMin() 
        {
            if (root != nullptr) {
                Node* minNode = findMin(root);
                cout << "Minimum item: " << minNode->data << "(" << minNode->count << ")" << endl;
            } 
            else {
                cout << "Tree is empty." << endl;
            }
        }

        void findSuccessor(int value) 
        {
            Node* successor = findSuccessor(root, value);
            if (successor != nullptr)
                cout << "Successor: " << successor->data << "(" << successor->count << ")" << endl;
        }

        void findPredecessor(int value) {
            Node* predecessor = findPredecessor(root, value);
            if (predecessor != nullptr)
                cout << "Predecessor: " << predecessor->data << "(" << predecessor->count << ")" << endl;
        }

        void displayTree() 
        {
            if (root != nullptr) 
            {
                cout << "Pre-order: ";
                displayPreOrder(root);
                cout << endl;

                cout << "In-order: ";
                displayInOrder(root);
                cout << endl;

                cout << "Post-order: ";
                displayPostOrder(root);
                cout << endl;
            } 
            else 
            {
                cout << "Tree is empty." << endl;
            }
        }
};

int main() {
    BinaryTree tree;
    int choice, item;

    do {
        cout << "Binary Search Tree\n";
        cout << "[1] Insert item\n";
        cout << "[2] Delete item\n";
        cout << "[3] Search item\n";
        cout << "[4] Find maximum\n";
        cout << "[5] Find minimum\n";
        cout << "[6] Find successor\n";
        cout << "[7] Find predecessor\n";
        cout << "[8] Display tree\n";
        cout << "[0] Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to insert: ";
                cin >> item;
                tree.insert(item);
                break;
            case 2:
                cout << "Enter item to delete: ";
                cin >> item;
                tree.remove(item);
                break;
            case 3:
                cout << "Enter item to search: ";
                cin >> item;
                tree.search(item);
                break;
            case 4:
                tree.findMax();
                break;
            case 5:
                tree.findMin();
                break;
            case 6:
                cout << "Enter item to find successor: ";
                cin >> item;
                tree.findSuccessor(item);
                break;
            case 7:
                cout << "Enter item to find predecessor: ";
                cin >> item;
                tree.findPredecessor(item);
                break;
            case 8:
                tree.displayTree();
                break;
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 0);

    return 0;
}