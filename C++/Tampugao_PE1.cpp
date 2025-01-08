//Tampugao, Mohammad Muraya
// The program demonstrate the conversion of infix to postfix
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream> //  is used to handle multiple digits and assist in the conversion of infix to postfix expressions. 
#include <cmath> //  used in the evaluation of expressions involving the modulo operator.

using namespace std;

void display() 
{
    cout << 
            "\n\nTampugao, Mohammad Muraya  (2022-60077)\n\n"
            "Dates Covered for Program Development: [March 2-11, 2024]\n\n"
            
            "The program demonstrates the conversion of infix to postfix and the result of evaluation of the expression.\n"
            "The main menu contains three choices as follows:\n"
            "[P] Program Description: Display program information.\n"
            "[E] Evaluate Expressio: Convert infix expression to postfix and evaluate it.\n"
            "[X] Exit: Terminates the program.\n\n"

           
           
           
            "Other Information:\n"
            "The program uses several libraries to aid in blocking possible invalid inputs and be able to comply with the requirements.\n This capable of handling decimal both as an input and output. It can output also a negative number but can't accept it as input\n\n";

}

bool check_Operator(char character) // this function checks if the input are the allowed operators
{
    return character == '-' || character == '+' || character== '/' || character == '*' || character == '%';
}

int op_precedence(char oprtrs) // this function serves as a way in assigning the hierarchy of the operators
{
    if (oprtrs == '+' || oprtrs == '-')
        return 1;// this is less priority than the following precendence
    else if (oprtrs == '*' || oprtrs == '/' || oprtrs == '%')
        return 2;// this has higher priority level
    else
        return 0; 
}

string Convert_infix_Postfix(const string& input_infix)  // this function is the conversion of infix to postfix expression
{
    stack<char> Stack_operators; // the stack holds the operators
    stringstream store_postfix; // stringstream is used to handle multiple digits and used in the process of conversion of infix to postfix.

    for (char c : input_infix) // this iterates in every character in the infix expression
    {
        if (isdigit(c) || c == '.') // isdigit is a number and if along with decimal is detected , it's appended in the postfix
        {
            store_postfix << c;
        } 

        else if (c == '(') 
        {
            Stack_operators.push(c);
        } 
        else if (c == ')') //if operator is closing parenthesis detected
        {
            
            while (!Stack_operators.empty() && Stack_operators.top() != '(') // while not yet empty and open parentehsis
            {
                store_postfix << ' ' << Stack_operators.top();// appending the operators at the postfix with a space prior to it
                Stack_operators.pop();
            }
            Stack_operators.pop(); // Poping the open parenthesis, as it's the last thing left
        } 
        else if (check_Operator(c)) 
        {
           store_postfix << ' '; // appending a space
            while (!Stack_operators.empty() && op_precedence(Stack_operators.top()) >= op_precedence(c)) 
            {
                //popping operators with higher or equal precedence and append it to the postfix
                store_postfix << Stack_operators.top() << ' ';
                Stack_operators.pop();
            }
            Stack_operators.push(c);
        }
    }

    while (!Stack_operators.empty()) // this iterates to appends whatever remaining in the stack, most probably those with lower precedence is what it deals with 
    {
        store_postfix << ' ' << Stack_operators.top();
        Stack_operators.pop();
    }

    return store_postfix.str(); //convert the postfix to string and return it
}



double evaluation_InfixPostfix(const string& postfix) //this function is for the evaluation
{
    stack<double> Stack_operand; // use to holds the operands
    stringstream ss(postfix); // ss(string stream); used for the breaking down of string of characters (tokenized)
    string divided_str; // initialization of the token

    while (ss >> divided_str)  // >> is use by string stream in sequential reading
    {
        if (isdigit(divided_str[0]) || (divided_str.size() > 1 && divided_str[0] == '-' && isdigit(divided_str[1]))) // if the divided_str is a number or even negative nos. 
        {
            Stack_operand.push(stod(divided_str)); // converts the string to double (stod) and push it afterwards
        } 

        else if (check_Operator(divided_str[0])) 
        {
            //pop the operands
            double operand_2 = Stack_operand.top();
            Stack_operand.pop();
            double operand_1 = Stack_operand.top();
            Stack_operand.pop();

            switch (divided_str[0]) // performing the necessary opertions and push it back
            {
                case '+':
                    Stack_operand.push(operand_1 + operand_2);
                    break;
                case '-':
                    Stack_operand.push(operand_1 - operand_2);
                    break;
                case '/':
                    Stack_operand.push(operand_1 / operand_2);
                    break;
                case '*':
                    if (operand_2 != 0)
                        Stack_operand.push(operand_1 * operand_2);
                    else 
                    {
                        cerr << "Error: Division by zero. Undefined. Try again\n"; // cout for error (cerr)
                        return 0;
                    }
                    break;
                case '%':
                    if (operand_2 != 0)
                        Stack_operand.push(fmod(operand_1, operand_2));
                    else 
                    {
                        cerr << "Error: Modulo by zero. Undefined hence, no remainder.\n";// cout for error
                        return 0;
                    }
                    break;
            }
        }
    }

    return Stack_operand.top(); // the top of the stack is the result
}


int main() 
{
    char select;
    bool invalid_Choice = false;

    cout << "Welcome to this Expression Evaluator program! Please choose an action to perform...\n";

    do 
    {
        cout << "\n[P] Program Description\n"
                "[E] Evaluate Expression(s)\n"
                "[X] Exit\n"
                "Choice: ";
        cin >> select;

        // Clear any remaining characters in the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Convert to lowercase
        select = tolower(select);

        if (select != 'p' && select != 'e' && select != 'x') 
        {
            cout << "\nInvalid choice. Please try again.\n";
            invalid_Choice = true;
        } 
        else 
        {
            invalid_Choice = false; // Reset the invalidChoice flag if a valid choice is made

            switch (select) 
            {
                case 'p': // program description
                    display();
                    break;
                case 'e':  // for the input and evaluation of the expression
                {
                    string input_infix;
                    cout << "\nEnter an infix expression:\n(Only allowed characters are: operators, parentheses, and digits):";
                    getline(cin, input_infix); //read the input and store to the infix string

                    // Input validation
                    bool valid = true;
                    for (char c : input_infix) 
                    {
                        if (!isdigit(c) && !check_Operator(c) && c != '(' && c != ')') 
                        {
                            valid = false;
                            break;
                        }
                    }

                    if (!valid) 
                    {
                        cout << "\nInvalid input. Please enter an infix expression containing only allowed characters.\n";
                        break;
                    }

                    string postfix = Convert_infix_Postfix(input_infix);
                    double evaluated_result = evaluation_InfixPostfix(postfix);

                    //display of infix and postfix expression, so as the result.
                    cout << "Infix: " << input_infix << endl;
                    cout << "Postfix: " << postfix << endl;
                    cout << "Result: " << evaluated_result << endl;
                    break;
                }
                case 'x': // exit the program
                    cout << "End. Bye...\n";
                    break;
            }
        }
    } 
    while (select != 'x');

    return 0;
}
