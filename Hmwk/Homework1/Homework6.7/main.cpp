// Author:      Sergio Hurtado
// Assignment:  Homework 1 (6.7)
// Class:       CSC17A - 43950
// Date:        03/16/2015
// Purpose:     This program will take the Fahrenheit temperatures from 0-20,
//              convert them into Celsius and display a table of these values.
//              Calculation : Celsius = (5/9) * (Fahranheit - 32)

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes

// Celsius - This function takes the Fahrenheit values from 0 to 20 and
// 	     converts their values to Celsius. It then displays the
//           converted values as well as the original values in the table.
void Celsius();

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	// Call Conversion Function
	Celsius();

	return 0;
}

// Fahrenheit to Celsius conversion table
void Celsius()
{
    float celsius = 0;

    //sets 1 decimal place. Left adjust and display table
    cout << setprecision(1);
    cout << fixed;   
    cout << left;
    cout << setw(16) << "Fahrenheit" << "Celsius" << endl;

    // Loop for all values to be displayed from 0 to 20 degrees Fahrenheit
    // Fahrenheit will be i in this program
    for (int i = 0; i <= 20; i++)
    {
        // Fahrenheit to Celsius conversion
	celsius = (5.0/9.0) * (i - 32);

	// Display table with Celsius and Fahrenheit equivalents
	cout << setw(16) << i << celsius << endl;
    }
    
	return;
}