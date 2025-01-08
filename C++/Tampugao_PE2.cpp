//Tampugao, Mohammad Muraya
// A program for demonstration of compression and expansion of a string
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to display program description
void display_Description() 
{
    cout << 
            "\n\nTampugao, Mohammad Muraya  (2022-60077)\n\n"
            "Dates Covered for Program Development: [March 4-11, 2024]\n\n"
            
            "The program demonstrates two main things: String compression and String expansion with the use a number and a case-sensitive alphabet.\n"
            "The main menu contains three choices as follows:\n"
            "[P] Program Description: Display program information.\n"
            "[E] String Expansion: Expand a compressed string.\n"
            "[C] String Compression: Compress an expanded string.\n"
            "[X] Exit: Terminates the program.\n\n"

             "Division of Task :Solo\n"
           
            "Other Information:\n"
            "In the input you can only enter a case-sensitive letters in string compression and only a digit and a case-sensitive letters for string expansion\n. Any input containing space will be scraped out, and combine the whole string to be converted.\n\n";
}

// Function to remove spaces from a string
// Function to remove spaces from a string
void removeSpaces(string& str) 
{
    string result = "";
    for (char c : str) {
        if (!isspace(c)) {
            result += c;
        }
    }
    str = result;
}

// Function to expand a compressed string
string Expanded_String(const string& input_compressed) 
{
    string expanded_str = ""; // it is where the expnaded string will be stored
    int repetition = 0; // a  to track the repetition of characters of the compressed string

    for (char c : input_compressed)  // loops through input(compressed string)
    {
        if (isdigit(c)) 
        {
            //conversion of te character to its integer value involving multiple digits to shift the value of decimal to the left and just add the value of c, then the letter enrepetitionered would  bwappend in a frequency depending on the value of c to the string
            repetition = repetition * 10 + (c - '0');
        } 
        else // a conmdition for those letter w/o number meaning it should be assumed as one
        {
            if (repetition == 0) repetition = 1; // If repetition is not specified, set it to 1
            expanded_str.append(repetition, c);
            repetition = 0;
        }
    }

    return expanded_str;
}

// Function to compress an expanded string
string Compressed_String(const string& input_expanded) 
{
    string compressed_str = ""; // where will the compressed string be stored
    int occurence = 1; //counter for the occurence of a character

    for (int i = 0; i < input_expanded.length(); i++) // iteration for the input_expanded string
    {
        if (input_expanded[i] == input_expanded[i + 1]) // if the character and the following character is the same, the occurence increments
        {
            occurence++;
        } 
        else 
        {
            if (occurence > 1) 
            {
                compressed_str += to_string(occurence);// convert to string and append it to the compressed string. This is the number of occurence
            }
            compressed_str += input_expanded[i]; //append the current character
            occurence = 1;
        }
    }

    return compressed_str;
}

int main() 
{
    char select;

    cout << "Welcome to this String Expansion/Compression program! Please choose an action to perform...\n";

    do {
        cout << "\n[P] Program Description\n"
                "[E] String Expansion\n"
                "[C] String Compression\n"
                "[X] Exit\n"
                "select: ";
        cin >> select;

        switch (tolower(select)) 
        {
            case 'p':
                display_Description();
                break;
            case 'e': 
            {
                string input_compressed;
                cout << "\nEnter the compressed string: ";
                cin.ignore(); // Ignore the newline character from previous input
                getline(cin, input_compressed); // Read the entire line including spaces
                removeSpaces(input_compressed); // Remove spaces from the input

                //restrictions for input to only accept alphabets and digit only
                bool valid = true;
                for (char c : input_compressed) 
                {
                    if (!isdigit(c) && !isalpha(c))  // if not digit or not alphabet
                    {
                        valid = false;
                        break;
                    }
                }

                if (!valid) 
                {
                    cout << "Invalid input. Please enter a valid compressed string.\n";
                    break;
                }

                string expanded_form = Expanded_String(input_compressed);
                cout << "\nExpanded Form: " << expanded_form << endl;
                break;
            }

            case 'c': 
            {
                string input_expanded;
                cout << "\nEnter the expanded string: ";
                cin.ignore(); // Ignore the newline character from previous input
                getline(cin, input_expanded); // Read the entire line including spaces
                removeSpaces(input_expanded); // Remove spaces from the input

                //restriction for possible invalid inputs
                bool valid = true;
                for (char c : input_expanded) 
                {
                    if (!isalpha(c)) 
                    {
                        valid = false;
                        break;
                    }
                }

                if (!valid) 
                {
                    cout << "\nInvalid input. Please enter a valid expanded string.\n";
                    break;
                }

                string compressed_form = Compressed_String(input_expanded); //calling the function
                cout << "\nCompressed Form: " << compressed_form << endl; // final compressed form
                break;
            }

            case 'x':
                cout << "Exit. Bye...\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } 
    while (tolower(select) != 'x');

    return 0;
}
