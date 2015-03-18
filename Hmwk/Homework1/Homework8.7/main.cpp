// Author:      Sergio Hurtado
// Assignment:  Homework 1 (6.7)
// Class:       CSC17A - 43950
// Date:        03/16/2015
// Purpose:     This program will take an array of 20 strings, sort the names in
//              alphabetical order by last name, and display the results.

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// FUNCTION PROTOTYPES
void selSort(string [], int);
void showAry(string [], int);

int main()
{
    // Set constant size for use with array
    const int SIZE = 20;

    // Initialize an array of 20 strings
    string name[SIZE] =
    { "Collins, Bill", "Smith, Bart", "Michalski, Jacob",
      "Griffin, Jim", "Sanchez, Manny", "Rubin, Sarah",
      "Taylor, Tyrone", "Johnson, Jill", "Allison, Jeff",
      "Moreno, Juan", "Wolfe, Bill", "Whitman, Jean",
      "Moretti, Bella", "Wu, Hong", "Patel, Renee",
      "Harrison, Rose", "Smith, Cathy", "Conroy, Patrick",
      "Kelly, Sean", "Holland, Beth" };

    // Display unsorted array of strings
    cout << "The unsorted array is: \n";
    showAry(name, SIZE);
    // Sort the array in alphabetical order
    selSort(name, SIZE);
    // Display the sorted array
    cout << endl;
    cout << "The sorted array is: \n";
    showAry(name, SIZE);

return 0;
}

// FUNCTION DEFENITIONS
// selectionSort function
void selSort(string name[], int elems)
{
    int start,              // Beginning of sort
        minIndx;            // Minimum index
    string strName;         // Store name
    // Step through array to sort
    for (start = 0; start < (elems - 1); start++)
    {
        minIndx = start;        // Set minimum index to starting point of array
        strName = name[start];  // Store first name 
        // Step through array to alphabetize
        for(int index = start + 1; index < elems; index++)
        {
            // Swap names alphabetically
            if (name[index] < strName)
            {
                strName = name[index]; 
                minIndx = index;
            }
        }
        // Reset sort
        name[minIndx] = name[start];
        name[start] = strName;
    }
}

// showArray Function
void showAry(string name[], int elems)
{
    // For loop to display elements in array
    for (int count = 0; count < elems; count++)
    {
        cout << name[count] << " " <<endl;
    }
} 
