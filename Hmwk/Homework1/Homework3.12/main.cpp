// Author:      Sergio Hurtado
// Assignment:  Homework 1 (3.12)
// Class:       CSC17A - 43950
// Date:        03/16/2015

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;


int main(int argc, char** argv) 
{
    string month;           // Store month
    int year;               // Store year
    float totCltd;          // Total amount collected in sales
    float staTax = 0.04;    // State tax collected
    float cntyTax = 0.02;   // County tax collected
    float sales;            // Total amount in sales
    float staTtl;           // Total in state taxes 
    float cntyTtl;          // Total in county taxes
    float total;            // Total sales tax

    // Get month, year, and amount collected
    cout << "Enter Month: ";
    getline(cin, month);
    cout << "Enter Year: ";
    cin >> year;
    cout << "Enter total amount collected at cash register: $";
    cin >> totCltd;

    // Calculate amount in sales
    sales = totCltd/1.06;
    // Calculate the state sales taxes
    staTtl = sales * staTax;
    // Calculate county sales taxes
    cntyTtl = sales * cntyTax;
    // Calculate the total amount of taxes
    total = staTtl + cntyTtl;

    // Display formatted output 
    cout << "\n------------------------------\n";
    cout << "Month: " << month << endl;
    cout << "Year:  " << year << endl;
    cout << "------------------------------\n";
    cout << setprecision(2) << fixed;
    cout << "Total collected: " << setw(10)
         << "$" << setw(9) << totCltd << endl;
    cout << "Sales: " << setw(20) << "$" << setw(9) 
         << sales << endl;
    cout << "County Sales Tax:" << setw(10) 
         << "$" << setw(9) << cntyTtl << endl;
    cout << "State Sales Tax: " << setw(10) 
         << "$" << setw(9) << staTtl << endl;
    cout << "Total Sales Tax: " << setw(10) 
         << "$" << setw(9) << total << endl << endl;

    return 0;
}

