// Author:      Sergio Hurtado
// Assignment:  Homework 2 (9.11)
// Class:       CSC17A - 43950
// Date:        03/18/2015
// Purpose:     This program is used to accept an integer array and the array's
//              size as arguments, and then creates a new array that is twice
//              the size of the argument array. The new elements will then be
//              initialized to 0.

#include <cstdlib>
#include <iostream>

using namespace std;
/*****************************************************************************
 * expSize:
 * The function expandSize accepts an integer array and an array size as
 * arguments. The program will then double the size of the array and initialize 
 * the new values to 0.
 * ***************************************************************************/
int* expSize (int*, int);

int main(int argc, char** argv) 
{
    // CONSTANTS
    //Number of elements
    const int SIZE = 10;    // Size for array

    // ARRAY Original
    int array [SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // POINTER to Array
    int* number = array;

    // DISPLAY ORIGINAL ARRAY
    cout << "Display the original values of the array: " << endl;
    for(int index = 0; index < SIZE; index++)
    {
        cout<<number[index] << " ";
    }
    // New line
    cout <<endl;

    // Call expand array
    number = expSize(array, SIZE);

    // Display the expanded array
    cout << "Display the new, expanded array: " << endl;
    for(int index = 0; index < SIZE * 2; index++)
    {
        cout << number[index] << " ";
    }
    // New line
    cout <<endl;

    // Deallocate memory
    delete[] number;        // Used to delete memory
    number = 0;             // Set location to null

    return 0;
}

// FUNCTION DEFINITION
// expSize Function Definition
int* expSize(int* array, int size)
{
    // Double size of the array
    int* expAray = new int[size * 2];

    // Fill first half of array with correct values
    for (int index = 0; index < size; index++)
        expAray[index] = array[index];

    // Set new values equal to 0.
    for (int index = size; index < size * 2; index++)
        expAray[index] = 0;

// Return the values of the expanded array.
return expAray;
}
