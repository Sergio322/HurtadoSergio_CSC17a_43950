// Author:      Sergio Hurtado
// Assignment:  Homework 1 (Mean, Median, Mode)
// Class:       CSC17A - 43950
// Date:        03/18/2015
// Purpose:     This program take an array of given values and dynamically
//              allocate new arrays to calculate the mean, median, and mode of
//              the particular set of numbers.

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Prototypes
// Get Mean
int mean(int nArray[], int iSize);
// Get Median
int median(int nArray[], int iSize);
// Get Mode
int mode(int nArray[], int iSize);

// Main
int main(int argc, char** argv) 
{
    // Initialize array with 24 values that repeat
    int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                     0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3};
    
    int size = 24;      // Size for array
    int sMean;          // Store Mean   
    int sMedian;        // Store Median
    int sMode;          // Store Mode
    
    // Call mean function, store in sMean
    sMean = mean(values, size);
    // Call median function, store in sMedian
    sMedian = median(values, size);
    // Call mode function, store in sMode
    sMode = mode(values, size);

    // Formatted Display
    cout << left;
    cout << setw(10) << "MEAN" << setw(10) << "MEDIAN" << setw(10) << "MODE";
    cout << endl;
    cout << setw(10) << sMean << setw(10) << sMedian << setw(10) << sMode;
    
    return 0;
}

// Get Mean
int mean(int nArray[], int size) 
{
    int sum = nArray[0];                // Set sum = to first element
    for (int i = 1; i < size; ++i)      // Loop through array
    {                                   // and add all numbers together
        sum += nArray[i];
    }
    // Return solution to calculation of mean
    return sum/size;
}

// Get Median
int median(int nArray[], int size)
{
    // Dynamically allocate a new array of same size and sort it
    int* pSort = new int[size];
    for (int i = 0; i < size; ++i) 
    {
        // Copy values over
        pSort[i] = nArray[i];   
    }
    // Step through newly created array and sort it
    for (int i = size - 1; i > 0; --i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            // Swap the values if number is bigger than the one after
            if (pSort[j] > pSort[j+1]) 
            {
                int temp = pSort[j];
                pSort[j] = pSort[j+1];
                pSort[j+1] = temp;
            }
        }
    }
    // Deallocate memory
    delete [] pSort;
}  

// Get Mode
int mode(int nArray[], int size) 
{
    // Dynamically allocate array of same size to hold number of repetitions
    int* repeats = new int[size];
    for (int i = 0; i < size; ++i) 
    {
        // Set initial array value to 0
        repeats[i] = 0;
        // Initialize j to 0
        int j = 0;
        // Keep count of number of times repeated
        while ((j < i) && (nArray[i] != nArray[j])) 
        {
            // Skip value if not repeated
            if (nArray[i] != nArray[j]) 
            {
                ++j;
            }
        }
        // Increment repeats array
        ++(repeats[j]);
    }
    // Initialize nModes to 0
    int nModes = 0;
    // Loop and count number of repeats
    for (int i = 1; i < size; ++i) 
    {
        // Set number of modes equal to number of repeats
        if (repeats[i] > repeats[nModes]) 
        {
            nModes = i;
        }
    }
    // Deallocate memory
    delete [] repeats;
    // Return nModes + 2
    return nArray[nModes + 2];
}