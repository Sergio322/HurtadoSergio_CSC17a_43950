// Author:      Sergio Hurtado
// Assignment:  Homework 2 (9.5)
// Class:       CSC17A - 43950
// Date:        03/18/2015
// Purpose:     This program will get two numbers from the user and put them
//              into the do something function. This function will multiply them
//              each by 10 and add the two numbers. This will be achieved using 
//              pointers instead of referenced variables.

#include <cstdlib>
#include <iostream>

using namespace std;

// Function Prototypes
// doSomething Function
int doSmtng(int *x, int *y);

int main(int argc, char** argv) 
{
    // Initialize Variables
    int y;              // Store first number
    int z;              // Store second number

    // Get first number from user
    cout << "Please enter a number: " << endl;
    cin >> y;
    // Get second number from the user
    cout << "Please enter another number: " << endl;
    cin >> z;

    // Call doSomething function
    // Multiply by 10 twice.
    doSmtng(&y, &z);
    doSmtng(&y, &z);
    // Add y + z and output
    cout << (y + z) << " = y(" << y << ") + z(" << z << ")" << endl << endl;

    return 0;
}

// Function Definitions
// doSomething Function
int doSmtng(int *x, int *y)
{
    // Temporary store
    int temp = *x;
    // Multiply by 10
    *x = *y * 10;
    // Store the value in second location
    *y = temp * 10;

// Return x + y
return *x + *y;
}
