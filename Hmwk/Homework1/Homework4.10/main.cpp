// Author:      Sergio Hurtado
// Assignment:  Homework 1 (4.10)
// Class:       CSC17A - 43950
// Date:        03/16/2015
// Purpose:     This program will ask the user for a number of units sold. It
//              will then take the appropriate discount and calculate the total
//              cost of the purchase and display it to the user.

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) 
{
    // Display menu
    cout << "---------------------------------" << endl;
    cout << "         Software Sales" << endl;
    cout << "---------------------------------" << endl << endl;

    int units;              // Store number of units sold
    float subtotal;         // Subtotal for number of units sold
    float total;            // Total after tax
    
    // Output formatting
    cout << left;
    // Get number of units sold from user
    cout << setw(31) << "Enter number of units sold: ";
    cin >> units;

    // Formatting for calculations
    cout << setprecision(2) << fixed;

    // If units sold is less than 10
    if(units > 0 && units < 10)
    {
        // Calculate total
        total = units * 99;
        cout << setw(30) << "The total is: " << "$" << total << endl << endl;
    }
    // If units sold is between 10 and 20
    else if(units >= 10 && units <= 19)
    {
        // Calculate total
        subtotal = (units * 99) * 0.20;
        total = (units * 99) - subtotal;
        cout << setw(30) << "The total is: " << "$" << total << endl << endl;
    }
    // If units sold is between 20 and 50
    else if(units >= 20 && units <=49)
    {
        // Calculate total
        subtotal = (units * 99) * 0.30;
        total = (units * 99) - subtotal;
        cout << setw(30) << "The total is: " << "$" << total << endl << endl;
    }
    // If units sold is between 50 and 100
    else if(units >= 50 && units <= 99)
    {
        // Calculate total
        subtotal = (units * 99) * 0.40;
        total = (units * 99) - subtotal;
        cout << setw(30) << "The total is: " << "$" << total << endl << endl;
    }
    // If units sold is greater than 100
    else if(units >= 100)
    {
        // Calculate total
        subtotal = (units * 99) * 0.50;
        total = (units * 99) - subtotal;
        cout << setw(30) << "The total is: " << "$" << total << endl << endl;
    }
    // If number input is invalid
    else
    {
        // Inform user
        cout << "The number of units has to be greater than 0!!" << endl 
             << endl;
    }
    
    return 0;
}