// Author:      Sergio Hurtado
// Assignment:  Homework 2 (9.1)
// Class:       CSC17A - 43950
// Date:        03/18/2015
// Purpose:     This program will call a function that dynamically allocates an 
//              array of integers of a size input by the user. The function will
//              then return a pointer to that array.

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes

// array: Dynamic allocation function
int *array (int);

int main(int argc, char** argv) 
{
    // Variable declarations
    int size;			// Hold the number of elements

    // Get size of array. Ask user for number of elements.
    cout << "Please enter the number of elements: " << endl;
    cin >> size;

    // Function call to get pointer to the new array.
    int *arayptr = array(size);
    // Release memory allocated.
    delete [] arayptr;

    // Display address
    cout << "The address of the array is: " << &arayptr;        
    
    return 0;
}

// FUNCTION DEFENITIONS
// array: Creating array dynamically
int *array(int size)
{
    // Create array
    int *ptr = new int[size];
    // Return pointer to new array
    return ptr;
}
