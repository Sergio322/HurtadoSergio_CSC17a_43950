/*  Problem 1: 

    Develop an application using structures for a customer
    that will determine if he/she has exceeded his/her checking 
    account balance. For each customer, the following 
    facts are available:

    a. Account number (Five digits only, i.e. test for this)
    b. Balance at the beginning of the month 
    c. Total of all checks written by this customer this month 
       Loop until customer is through entering checks.
    d. Total of all deposits credited to this customer's account this 
       month.  Loop until customer is through entering deposits.

    The program should input each of these facts from input dialogs as 
    integers, store in a structure, calculate the new balance, 
    display the new balance and debit the account $12 if overdrawn. 
    Also, if overdrawn, tell the customer the additional $12 fee 
    has been accessed and what the balance would be with this fee included.
 */

#include "Problem1.h"
#include "MidtermHeader.h"

struct Account 
{
    char acctNum[5];        // User's account number must be 5 digits
    float totWith;          // Total amount withdrawn from the account
    float totDpst;          // Total amount deposited to the account
    float balance;          // Current balance of the account   
};

Account customr;            // Create customr object of Account type
// Problem 1 solution 
void soltn1()
{
    char control;           // Control menus and runs
    bool exit = false;      // For user to exit program
    
    // Display problem
    cout << "-----------------------------------------" << endl;
    cout << "  Problem 1: [Checking Account Balance]  " << endl;
    cout << "-----------------------------------------" << endl;
    
    // Display current stats
    cout << fixed;
    cout << setprecision(2);
    do
    {
        cout << "Current Balance: $" << customr.balance << endl;
        cout << "Please select from the following options:" << endl;
        cout << endl;
        cout << "|1| -> View or change account number" << endl;
        cout << "|2| -> Check bank account balance" << endl;
        cout << "|3| -> Make a deposit" << endl;
        cout << "|4| -> Make a withdrawal" << endl;
        cout << "|5| -> Return to main menu" << endl;
        cout << endl;
        cin >> control;
        cout << endl;
        
        // Switch on user choice
        switch(control)
        {
            case '1' : getAcc();    break;
            case '2' : viewBal();   break;
            case '3' : deposit();   break;
            case '4' : withdrw();   break;
            case '5' : exit = true; break;           
        }
        cout << endl;    
    }while (!exit);
    // Clear screen 
    clrScrn();
}

/* getAcc function: This function will get an account number from the user and
                    verify that it is in proper format                       */
void getAcc()
{
    char usrAcct[5];        // Account number from user
    char *chrptr = usrAcct; // Character pointer to usrAcct
    char control = '0';     // Control character for menu
    int inCount = 0;        // Count number of characters input
    bool valid = true;      // Check if user input is in valid format 
    int i = 0;              // For loops
    
    cout << "Your account number is: " << customr.acctNum << endl;
    cout << "Would you like to change your account number? (Y/N)" << endl;
    cin >> control;
    cout << endl;
    // If user chooses to change account number
    if (control == 'y' || control == 'Y')
    {
        do
        {
            cout << "Please enter a new account number: " << endl;
            cin.getline (chrptr, 256);
            inCount = cin.gcount();
            cout << endl;
            valid = true; 
            
            // Input checking for too many characters
            if (inCount != 6)
            {
                cout << "Please enter five digits only." << endl;
                valid = false;
            }
            inCount--; 
            // Input checking for numbers only
            for (i = 0; i < inCount; i++)
            {
                if (!isdigit(chrptr[i]))
                {
                    cout << chrptr[i];
                    cout << "Please enter numbers only." << endl;
                    valid = false;
                }
            }   
            // If all is well, set new account number
            if (valid)
            {
                for (i = 0; i < inCount; i++)
                {
                    customr.acctNum[i] = chrptr[i];
                }
                customr.acctNum[i] = '\0';          // Attach null terminator
                cout << "Your new account number is: " << customr.acctNum;
                cout << endl; 
                // Reset amounts to 0
                customr.balance = 0;
                customr.totDpst = 0;
                customr.totWith = 0;
            }
        }while (!valid);     
    }   // If user does not want to change account number
    else if (control == 'N' || control == 'n')
    {
        cout << endl << endl;
    }
    // Default
    else 
    {
        cin.ignore(256, '\n');
        cout << endl << endl;
    }  
    // Clear screen 
    clrScrn();
}

/* withdrw: This function will allow the user to input the amount of each check
 *          withdrawn from the account and display current balance as well as
 *          a warning message if the account has been overdrawn               */
void withdrw()
{
    bool done = false;          // Flag for user entering checks
    float chckAmt = 0;          // Amount being withdrawn
    float chckTtl = 0;          // Total of all checks
    int chkCount;               // How many checks were entered
    char control;               // Control variable for menu
    // Clear screen 
    clrScrn();
    // Get amount of checks
    do
    {
        cout << "Please enter the amount of the check: " << endl;
        cout << "$ ";
        cin >> chckAmt;
        chckTtl += chckAmt;
        customr.totWith = chckTtl;
        cout << endl;
        // Display new balance after check is withdrawn
        customr.balance = (customr.balance - chckAmt);
        // Check if overdrawn
        if (customr.balance < 0)
        {
            cout << "Account number: " << customr.acctNum
                 << " has been overdrawn." << endl;
            cout << "A $12 fee will be charged to this account." << endl;
            // Calculate new balance
            customr.balance = (customr.balance - 12);            
        }
        // Display current balance
        cout << fixed;
        cout << setprecision(2);
        cout << "Your current balance is: $" << customr.balance << endl;
        cout << endl;
        cout << "Would you like to continue withdrawing checks? (Y/N)" << endl;
        cin >> control;
        cout << endl;
        if (control == 'N' || control == 'n')
        {
            cout << "Total amount withdrawn this month: $" << chckTtl << endl;
            done = true;            // No more checks to input 
        }
        chkCount++;                 // Increment number of checks input
    }while (!done);
}

/* deposit: This function will allow the user to input the amount of each 
 *          deposit made to the account and display current balance          */
void deposit()
{
    bool done = false;          // Is the user done entering deposits 
    float depAmt = 0;           // Amount being deposited
    float depTtl = 0;           // Total amount of all deposits
    int depCount;               // How many deposits have been made
    char control;               // Control variable for menu
    // Clear screen
    clrScrn();
    // Get amounts being deposited and calculate new balance
    do
    {
        cout << "Please enter the amount you are depositing: " << endl;
        cout << "$ ";
        cin >> depAmt;  
        depTtl += depAmt;
        customr.totDpst = depTtl;
        customr.balance = (customr.balance + depAmt);
        // Display current balance
        cout << "Your current balance is : $" << customr.balance << endl;
        cout << "Would you like to make another deposit? (Y/N)" << endl;
        cin >> control;
        cout << endl;
        if (control == 'N' || control =='n')
        {
            cout << "Total amount deposited this month: $" << depTtl << endl;
            done = true;
        }
        depCount++;        
    }while (!done);  
}

/* viewBal: This function will allow the user to view their current account
 *          balance. It will also allow the user to correct their starting 
 *          balance                                                           */
void viewBal()
{
    char control;               // Control variable for menu
    float newBal;               // Stores the user's balance
    // Clear screen 
    clrScrn();
    // Display current balance
    cout << left;
    cout << setw(20) << "BALANCE" 
         << setw(20) << "DEPOSITS" 
         << setw(20) << "WITHDRAWALS" << endl;
    cout << "$" << setw(19) << customr.balance
         << "$" << setw(19) << customr.totDpst
         << "$" << setw(19) << customr.totWith << endl << endl;
    // Change starting balance?
    cout << "Would you like to change your starting balance? (Y/N)" << endl;
    cin >> control;
    cout << endl;
    // Does user want to change starting balance
    if (control == 'Y' || control == 'y')
    {
        cout << "Please enter your starting balance:" << endl;
        cout << "$ ";
        cin >> newBal;
        customr.balance = newBal;
        customr.totDpst = 0;
        customr.totWith = 0;
        cout << endl;
    }
    else if (control == 'N' || control == 'n')
    {
        cout << endl;
    }
    // If all is well
    else if (newBal > 0)
    {
        customr.balance = newBal;
        cout << "The new balance was recorded as: $" << customr.balance << endl;
    }
    else if (newBal < 0)
    {
        cout << "The starting balance should less than $0.00." << endl;
        cout << "Your new balance was not recorded." << endl;
    }
    else 
    {
        cout << "An incorrect value was input, new balance not recorded.";
        cout << endl;
    }
}