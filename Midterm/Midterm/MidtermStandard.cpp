#include "MidtermHeader.h"

// Display menu function
void dispMnu(char& choice)
{
    bool isValid = false;       // Is input choice valid
    // Display menu
    do
    {
        cout << endl;
        cout << "-----------------------------"
                "          Main Menu          "
                "-----------------------------";
        cout << endl;
        cout << "Please choose an item from the following options:" << endl;
        cout << "|1| -> Problem 1 : [Checking Account Balance]" << endl;
        cout << "|2| -> Problem 2 : [Calculate Gross Pay]" << endl;
        cout << "|3| -> Problem 3 : [Mean Median and Mode]" << endl;
        cout << "|4| -> Problem 4 : [Encrypt and Decrypt Data]" << endl;
        cout << "|5| -> Problem 5 : [Largest Factorial Per Data Type]" << endl;
        cout << "|6| -> Problem 6 : [Conversions]" << endl;
        cout << "|0| -> Exit" << endl << endl;
        // Get user menu choice
        cin >> choice;
        cout << endl;
        
        // Validate user input
        if (  choice == '1'
            ||choice == '2'
            ||choice == '3'
            ||choice == '4'
            ||choice == '5'
            ||choice == '6'
            ||choice == '0')
        {
            isValid = true;
        }
        else 
        {
            cin.ignore();
            cout << "You entered an invalid menu choice." << endl;
            cout << "Please try again." << endl;
            isValid = false;            
        }  
    } while (!isValid);     // End do while for menu
}  

// Input control
bool inpLoop (char& inp)
{
    bool valid = false;
    do
    {
        if (inp == 'Y' || inp == 'y')
        {
            valid = true;
            return false;
        }
        else if (inp == 'N' || inp == 'n')
        {
            valid = true;
            return true;
        }
        else
        {
            cout << endl;
            cout << "Invalid input. Please try again: ";
            cin >> inp;
            valid = false;
        }           
    }while (!valid);
}  

// Clear screen
void clrScrn()
{
    int x = 1; 
    int y = 100;
    do
    {
        cout << "\n";
        x++;
    }while(x < y);   
}