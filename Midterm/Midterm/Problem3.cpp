/*  Problem 3:

    Write a function using the following structure and prototype.

    struct statsResult
    {
        float avg;
        float median;
        int *mode;   //array containing the modes
        int nModes;  //number of modes in the array
        int maxFreq; //max frequency of modes
    };

    statsResult *avgMedMode(int *,int); 

    The function takes in an integer array and the size of the array.
    Then returns a pointer to a structure containing the average, median
    and mode.  You will then write a printStat() function that will print
    the results contained in the stats structure.  I will input a small 
    array to test this out so ask for how many inputs to fill the array, 
    then the values to place into the array.  Make sure you delete the 
    dynamic array creation for the mode when you exit the problem.
 */

#include "Problem3.h"

using namespace std;

void soltn3()
{
    int numDgts = 0;
    statsResult *avgMm;
    cout << "A couple of the functions in this problem are not" << endl;
    cout << "functioning properly. Not sure why." << endl;
    cout << "How many digits will be entered?\n";
    cout << "User Input: ";
    cin.clear();
    cin.ignore(1000, '\n');
    cin >> numDgts;
    int *usrNums = new int[numDgts];
    for(int count = 0; count < numDgts; count++)
    {
        cout << "User Input #" << count+1 << ": ";
        cin >> usrNums[count];
    }
    plcmnt(usrNums, numDgts);
    avgMm = avgMedMode(usrNums, numDgts);
    printStat(avgMm);
    delete avgMm;
    delete []usrNums;
}

//Problem 3 Functions
//Calculates
statsResult *avgMedMode(int *usrNums, int numDgts)
{
    float num = 0.0;
    bool change = false;
    statsResult *result = new statsResult();
    int minMode = 0;
    int nmodes = 0;
    int freqCnt = 0;
    result-> maxFreq = 0;
    
    for(int count = 0; count < numDgts; count++)
    {
        num = num + usrNums[count];
    }
    //Calculates the average
    result-> avg = num/numDgts;
    //Looks for the median
    if (numDgts %2 == 1)
    {
        result-> median = usrNums[(numDgts - 1)/2];
    }
    else
    {
        result-> median = (usrNums[numDgts/2] +
        usrNums[1 + (numDgts /2)])/2;
    }
    num = 1;
    for(int count = 0; count < numDgts - 1; count++)
    {
        if(usrNums[count] == usrNums[count + 1])
        {
            num++;
        }
        else if(usrNums[count] != usrNums[count + 1])
        {
            if(num > result -> maxFreq)
            result -> maxFreq = num;
            num= 1;
        }
        else if(count == numDgts - 2 && result -> maxFreq<num)
        result -> maxFreq=num;
    }
    //Finds the mode
    for (int count = 0; count < numDgts; count++) 
    {
        if (usrNums[count] > minMode)
        {
            minMode = usrNums[count];
        }
    }
    result -> mode = &minMode;
    
    //Find the number of modes
    for(int count = 1; count < numDgts; count++)
    {
        if(usrNums[count] == usrNums[count - 1])
        {
            if(result -> maxFreq == freqCnt)
            {
                nmodes++;
            }
            freqCnt++;
        }
        else
        {
            freqCnt=0;
        }
    }
    result->nModes = nmodes+2;
    return result;
}

void plcmnt(int *usrNums, int numDgts)
{
    bool change;
    do
    {
        int num;
        change = false;
        for(int count = 0; count < numDgts; count++)
        {
            if(usrNums[count] > usrNums[count + 1])
            {
                num = usrNums[count];
                usrNums[count] = usrNums[count + 1];
                usrNums[count + 1] = num;
                change = true;
            }
        }
    }while(change == true);
}

//Displays Result
void printStat(statsResult *avgMm)
{
    cout << fixed;
    cout << setprecision(2);
    cout << "\n***Results***\n";
    cout << "-------------------------------------------------";
    cout << "\nAverage: " << avgMm -> avg;
    cout << "\nMedian: " << avgMm -> median;
    cout << "\nNumber of Modes: " << avgMm ->nModes;
    cout << "\nMax Frequency: " << avgMm -> maxFreq;
    cout << "\nMode: " << *avgMm -> mode;
    cout << "\n-----------------------------------------------\n";
}