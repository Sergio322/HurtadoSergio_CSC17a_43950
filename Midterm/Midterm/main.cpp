/* 
 * File         : Midterm
 * Author       : Sergio Hurtado
 * Description  : 7 Problems in one menu
 * Date Due     : 04/12/2015
 */

// Libraries
#include <iostream>

// Header Files
#include "MidtermHeader.h"
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"
#include "Problem5.h"
#include "Problem6.h"

using namespace std;

int main(int argc, char** argv) 
{
    char choice;                // User menu control
    bool exit = false;          // Exit flag for user control    
    // Standard info
    cout << "Programmed By: " << endl;
    cout << "Name       : Sergio Hurtado" << endl;
    cout << "ID #       : 2265982" << endl;
    cout << "Class      : CIS 17A - Section 43950" << endl;
    cout << "Description: Midterm Solutions" << endl;
    cout << "Date Due   : 04/12/2015" << endl;
    
    // Menu for user
    do
    {
        dispMnu(choice);        // Display menu for user
        switch(choice)          // Switch to proper menu based on user choice
        {
            case '1':
                cout << endl;
                soltn1();       // Display problem 1
                break;     
            case '2':
                cout << endl;
                soltn2();       // Display problem 2
                break;
            case '3':
                cout << endl;
                soltn3();       // Display problem 3
                break;
            case '4':
                cout << endl;
                soltn4();       // Display problem 4
                break;
            case '5':
                cout << endl;
                soltn5();       // Display problem 5
                break;
            case '6':
                cout << endl;
                soltn6();       // Display problem 6
                break;
            case '0':
                cout << endl;
                exit = true;
                break;
        }    
    }while (!exit);
    cout << "The program will now exit." << endl;
    
    return 0;
}

