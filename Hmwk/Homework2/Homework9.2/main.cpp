// Author:      Sergio Hurtado
// Assignment:  Homework 2 (9.2)
// Class:       CSC17A - 43950
// Date:        03/18/2015
// Purpose:     This program will create an array dynamically to store a number
//              of test scores chosen by the user. It will then take those 
//              scores, put them in ascending order, calculate the average and 
//              display it to the user.

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// FUNCTION PROTOTYPES

/************************************************************************
 * getAray: This function will allocate memory for an array of user
 *			 determined size.
 ************************************************************************/
int *getAray(int);

/*************************************************************************
 * calcAverage: This function will take all of the input scores and
 * 		calculate the average of these scores. It will then return
 * 		the average.
 *************************************************************************/
int calcAvg(int total, int size, int value[]);

int main(int argc, char** argv) 
{
    // Initialize variables
    int *score;				// Store scores input
    int	total = 0;			// Total scores input
    int	average;			// Store average of all scores
    int numStud;			// Number of scores to be stored
    int	i=0;				// Loop control variable

    // Display Title
    cout << setw(40) << "** Test Score Calculation ** " << endl << endl;
    // Get number of test scores to be saved
    cout << "How many student scores do you want to enter?  ";
    cin >> numStud;

    // Call getArray function. Allocate new memory for given test scores.
    score = getAray(numStud);

    // Fill array with score for each student.
    for (i =0 ; i <numStud ;i++)
    {
        // Ask user for student scores.
        cout << endl;
        cout << "Enter the score of student "<< (i + 1) <<": ";
	cin >> score[i];
	// Input Validation for negative numbers.
	if (score[i] < 0)
	{
            cout <<"Invalid: please enter test score in positive number.";
            cout << endl;
            cout <<"Enter the score of student " << (i + 1) << ": ";
            cin >> score[i];
	}
    }

    // Call calcAverage function. Get average of scores.
    average = calcAvg(total,numStud,score);

    // Fill the array with values
    for (int i = 0; i < numStud; i++)
    {
        score[i] = i;
    }

    // Display average of scores.
    cout << endl;
    cout << " ** Average Score of " << i << " students is "
	 << average << " **" << endl << endl;

    // Release the dynamically allocated memory.
    delete [] score;
    // Send score to null location.
    score = 0;
    
    return 0;
}

// FUNCTION DEFINITIONS

// getArray function
int *getAray( int num)
{
    // Pointer to location of new array.
    int *score;

    // If value user enters is negative. Send to Null.
    if (num <=0)
    return NULL;

    // Allocate new memory.
    score = new int[num];
    return score;
}

// calcAverage function
int calcAvg(int total, int size, int value[])
{
    // Step through array adding all scores.
    for (int i=0; i < size; i++)
    {
        total += value[i];
    }
    // Calculate average of test scores
    int average;
    average = total / size;
    
// Return average test score.
return average;
}
