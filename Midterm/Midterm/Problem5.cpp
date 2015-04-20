/*  Problem 5:

    a) Using a byte variable, what is the largest factorial that can 
    be calculated.  A factorial is simply 

    n! = 1 * 2 * 3 * 4 ... * (n-2) * (n-1) * n

    For instance, 1! = 1,  2! = 2,  3! = 6,  4! = 24,  5! = 120 etc....

    b)  What would be the largest factorial using short, int, long, float, 
    double, etc...  Use all the primitive data types that you are familiar 
    with.

    Note:  I want you to have fun investigating this and the program you 
    turn in should just print "cout" the final results.  You don't know 
    how to capture errors yet so run each till it overflows then back off by 1.
    Don't need the program that tests for this.
*/

#include "Problem5.h"

void soltn5()
{
    bool isValid = false;       // Is input choice valid
    int number = 1;         // Hold the value of the number of factorial
    char choice;  
    bool exit = false;
    // Display menu
    do
    {
        cout << endl;
        cout << "-------------------------------"
                "          Factorial Menu       "
                "-------------------------------";
        cout << endl;
        cout << endl;
        cout << "We will be testing the largest factorial that can be" << endl;
        cout << "calculated in a one byte variable..." << endl;
        cout << "Choose from the following list: " << endl;
        cout << endl;
        
        cout << "|1| -> Unsigned short int Factorial" << endl
             << "|2| -> Signed short int factorial" << endl
             << "|3| -> Unsigned int Factorial" << endl
             << "|4| -> Singed int Factorial" << endl
             << "|5| -> Unsigned long int Factorial" << endl
             << "|6| -> Signed long int Factorial" << endl
             << "|7| -> Float Factorial" << endl
             << "|8| -> Double Factorial" << endl
             << "|9| -> Largest Factorial of each type" << endl
             << "|0| -> Exit" << endl;
        cin >> choice;
        cout << endl;
        
        // Validate user input
        if (  choice == '1'
            ||choice == '2'
            ||choice == '3'
            ||choice == '4'
            ||choice == '5'
            ||choice == '6'
            ||choice == '7'
            ||choice == '8'
            ||choice == '9'
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
        // Switch
        switch(choice)          // Switch to proper menu based on user choice
        {
            case '1':
                cout << endl;
                usiFact();       // Display problem 1
                break;     
            case '2':
                cout << endl;
                ssiFact();       // Display problem 2
                break;
            case '3':
                cout << endl;
                uiFact();       // Display problem 3
                break;
            case '4':
                cout << endl;
                siFact();       // Display problem 4
                break;
            case '5':
                cout << endl;
                uliFact();
                break;
            case '6':
                cout << endl;
                sliFact();
                break;
            case '7':
                cout << endl;
                fFact();
                break;
            case '8':
                cout << endl;
                dFact();
                break;
            case '9':
                cout << endl;
                larFac();
            case '0':
                cout << endl;
                exit = true;
        }        
    } while (!isValid && !exit);     // End do while for menu
}

// Unsigned short int
void usiFact()
{
    unsigned short int factrl = 1;          // Hold factorial of number
    unsigned short int number = 1;                         // Hold number
       
    cout << "You are in unsigned short int..." << endl;
    cout << "Enter a number: ";
    cin >> number;
    cout << endl;
    
    for (int i = 1; i <= number; i++)
    {
        factrl = factrl * i;    
    }
    
    cout << "Factorial of given number is: " << factrl << endl;
}

// Unsigned short int
void ssiFact()
{
    signed short int factrl = 1;          // Hold factorial of number
    signed short int number = 1;          // Hold number
        
    cout << "You are in signed short int..." << endl;
    cout << "Enter a number: ";
    cin >> number;
    cout << endl;
    
    for (int i = 1; i <= number; i++)
    {
        factrl = factrl * i;    
    }
    
    cout << "Factorial of given number is: " << factrl << endl;
}

// Unsigned short int
void uiFact()
{
    unsigned int factrl = 1;          // Hold factorial of number
    unsigned int number = 1;          // Hold number
        
    cout << "You are in unsigned int..." << endl;
    cout << "Enter a number: ";
    cin >> number;
    cout << endl;
    
    for (int i = 1; i <= number; i++)
    {
        factrl = factrl * i;    
    }
    
    cout << "Factorial of given number is: " << factrl << endl;
}

// Unsigned short int
void siFact()
{
    signed int factrl = 1;          // Hold factorial of number
    signed int number = 1;          // Hold number
        
    cout << "You are in signed int..." << endl;
    cout << "Enter a number: ";
    cin >> number;
    cout << endl;
    
    for (int i = 1; i <= number; i++)
    {
        factrl = factrl * i;    
    }
    
    cout << "Factorial of given number is: " << factrl << endl;
}

// Unsigned short int
void uliFact()
{
    unsigned long int factrl = 1;          // Hold factorial of number
    unsigned long int number = 1;                         // Hold number
        
    cout << "You are in unsigned long int..." << endl;
    cout << "Enter a number: ";
    cin >> number;
    cout << endl;
    
    for (int i = 1; i <= number; i++)
    {
        factrl = factrl * i;    
    }
    
    cout << "Factorial of given number is: " << factrl << endl;
}

// Unsigned short int
void sliFact()
{
    signed long int factrl = 1;          // Hold factorial of number
    signed long int number = 1;                         // Hold number
        
    cout << "You are in signed long int..." << endl;
    cout << "Enter a number: ";
    cin >> number;
    cout << endl;
    
    for (int i = 1; i <= number; i++)
    {
        factrl = factrl * i;    
    }
    
    cout << "Factorial of given number is: " << factrl << endl;
}

// Unsigned short int
void fFact()
{
    float factrl = 1.0;          // Hold factorial of number
    float number = 1.0;                         // Hold number
        
    cout << "You are in float..." << endl;
    cout << "Enter a number: ";
    cin >> number;
    cout << endl;
    
    for (int i = 1; i <= number; i++)
    {
        factrl = factrl * i;    
    }
    
    cout << "Factorial of given number is: " << factrl << endl;
}

// Unsigned short int
void dFact()
{
    double factrl = 1;          // Hold factorial of number
    double number = 1;                         // Hold number
        
    cout << "You are in double..." << endl;
    cout << "Enter a number: ";
    cin >> number;
    cout << endl;
    
    for (int i = 1; i <= number; i++)
    {
        factrl = factrl * i;    
    }
    
    cout << "Factorial of given number is: " << factrl << endl;
}

// Largest Factorials
void larFac()
{
    cout << "Below are the values of the largest factorials" << endl;
    cout << "for each data type:" << endl << endl;
    
    cout << "Unsigned short: 8!" << endl;
    cout << "Signed short: 7!" << endl;
    cout << "Unsigned int: 8!" << endl;
    cout << "Signed int: 7!" << endl;
    cout << "Unsigned long: 12!" << endl;
    cout << "Signed long: 12!" << endl;
    cout << "Float: 34!" << endl;
    cout << "Double: 170!" << endl;
}