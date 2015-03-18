// Author:      Sergio Hurtado
// Assignment:  Homework 1 (5.11)
// Class:       CSC17A - 43950
// Date:        03/16/2015
// Purpose:     This program will predict the size of a population of organisms
//              by getting a starting number of organisms, the average daily
//              population increase, and the number of days for which it will
//              increase

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) 
{
    float numOrgs = 0.0;            // Number of organisms
    int dayMult = 0;                // Number of days to multiply
    float dalyTtl = 0.0;            // Daily increase total
      
    // Get the starting number of organisms
    cout << "Enter the starting number of organisms: ";
    cin >> numOrgs;
    // Error checking for number of organisms to be more than 2 
    while(numOrgs < 2)
    {
        cout << "The starting number of organisms must be at least 2.";
        cout << "Enter the starting number of organisms: ";
        cin >> numOrgs;
    }
    
    // Get percentage of daily increase of the population
    cout << "Enter the average daily population increase percentage: ";
    cin >> dalyTtl;
    // Error checking for percentage daily increase
    while(dalyTtl < 0)
    {
        cout << "The average daily population increase must be a positive value.";
        cout << "Enter the average daily population increase percentage: ";
        cin >> dalyTtl;
    }
      
    // Get number of days that the population will be multiplying
    cout << "Enter the number of days they will multiply: ";
    cin >> dayMult;
    // Error checking for number of days to be at least 1
    while(dayMult < 1)
    {
        cout << "The number of days must be at least 1.";
        cout << "Enter the number of days they will multiply: ";
        cin >> dayMult;
    }
      
    // display daily populations size
    cout << left;
    cout << setprecision(0) << fixed;
    cout << setw(15) << "DAY" << "POPULATION SIZE";
    cout << endl;
    
    for (int count = 0; count != dayMult; count++)
    {
        // Calculate total number of organisms
        numOrgs = numOrgs + (numOrgs * dalyTtl);
        // Output daily organism count
        cout << setw(15) << count + 1 << setw(15) << numOrgs << endl;
    }
  
    return 0;
}