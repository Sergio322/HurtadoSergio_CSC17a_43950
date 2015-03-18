// Author:      Sergio Hurtado
// Assignment:  Homework 2 (9.10)
// Class:       CSC17A - 43950
// Date:        03/18/2015
// Purpose:     This program will take an array of values and reverse the order
//              of the elements. It will display the values of the function
//              before they are reversed and then again after they are reversed.

#include <iomanip>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

// Function Prototypes
/******************************************************************************
 * reverse:
 * 		This function will take all of the values in the original array
 * 		and reverse the order.
 *****************************************************************************/
void reverse(int [], int);
/******************************************************************************
 * prntAry:
 * 		This function will take all of the reversed values and display
 * 		them to the console.
 *****************************************************************************/
void prntAry(int [], int );

int main(int argc, char** argv) 
{
    // CONSTANTS
    const int SIZE = 10;        // Size of array

    // Initialize array with 10 integers
    int arr [SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Display array before it's reversed
    cout << "Before reverse: " << endl;
    // printArray function call
    prntAry(arr, SIZE);

    // reverse function call
    reverse(arr, SIZE);
    // Skip a line
    cout << endl;
    // Display array after it's reversed
    cout << "After reverse: " << endl;
    // printArray function call
    prntAry(arr, SIZE);

    return 0;
}

// printArray Function Definition
void prntAry(int arr[], int count)
{
    // Print each element in array
    for(int i = 0; i < count; ++i)
        cout << arr[i] << ' ';
    // Skip a line
    cout << endl;
}

// reverse Function definition
void reverse(int arr[], int count)
{
    int temp;                           // Value holder
    // Step through array and reverse order
    for (int i = 0; i < count / 2; ++i)
    {
        temp = arr[i];
	arr[i] = arr[count - i - 1];
	arr[count - i - 1] = temp;
    }
}
