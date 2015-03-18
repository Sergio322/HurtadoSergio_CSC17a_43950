// Author:      Sergio Hurtado
// Assignment:  Homework 1 (3.13)
// Class:       CSC17A - 43950
// Date:        03/16/2015
// Purpose: This program will get the value of a property from the user and it
//          will calculate and display the assessment value, and total amount
//          of taxes

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;


int main(int argc, char** argv) 
{
    // CONSTANTS
    const float ASMTTAX = 0.60; // 60% of the property's value
    const float PPTYTAX = 0.64; // 64 cents per $100
    
    float pptyVal;          // Property value       
    float taxTtl;           // Total amount of taxes
    float asmtVal;          // Assessment value of property

    // Get value of property from user
    cout << "Enter the actual value of the property: ";
    cin >> pptyVal;

    // Calculate assessment value
    asmtVal = pptyVal * ASMTTAX;
    // Calculate sales tax
    taxTtl = (asmtVal/100) * PPTYTAX;

    // Formatted output
    cout << left;
    cout << setprecision(2) << fixed;
    cout << "\n-----------------------------------------\n";
    cout << setw (25) << "The assessment value is: "
         << setw (4) << "$" << asmtVal << endl;
    cout << setw (25) << "The property tax is: "
         << setw (4) << "$" <<taxTtl << endl 
         << endl;
    
    return 0;
}