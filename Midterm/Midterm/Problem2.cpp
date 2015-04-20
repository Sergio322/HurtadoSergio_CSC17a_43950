/*  Problem 2:
  
    Develop an application using an array of structures that will 
    determine the gross pay for any number of employees input. The company pays 
    "straight-time" for the first 20 hours worked, double time for 
    all hours worked in excess of 20 hours but less than 40 hours, 
    and triple time for any hours worked over 40 hours.

    The program should be able to loop and input the employee's name, 
    hours worked, and the rate of pay.  Once this has been done then 
    the gross pay should be calculated.  Output all the pertinent information
    with respect to the employee as a check and the process starts all over 
    again until you input an invalid rate of pay or hours worked.  This
    means a negative rate of pay or negative number of hours worked is
    not acceptable.
*/

#include "Problem2.h"
#include "MidtermHeader.h"

void soltn2()
{
    int numRecs = 0;        // Number of records user chooses to enter
    int empNum = 1;         // Counter for employees
    float totWgs = 0;       // Total wages paid out
    int i = 0;              // Loop counter
    
    // Display problem
    cout << "-----------------------------------------" << endl;
    cout << "  Problem 2: [Calculate Gross Pay]       " << endl;
    cout << "-----------------------------------------" << endl;
    
    // Prepare for input
    cin.clear();                // Clear input buffer
    cin.ignore(256, '\n');      // Make sure buffer is clean
    cout << fixed;              // Proper formatting
    cout << setprecision(2);
    // How many records?
    cout << "How many records will you be entering?" << endl;
    cin >> numRecs;
    cout << endl;
    // Dynamically create array of structs for employee info
    PayStmt *emp = new PayStmt[numRecs];
    
    // Get info for each employee
    cout << "Please enter the following information for employee # "
         << empNum << endl;
    for (i = 0; i < numRecs; i++)
    {
        cin.clear();            // Clear input buffer to prevent read errors
        cin.ignore(256,'\n');
        cout << left;
        cout << setw(15) << "Employee # : " << empNum << endl;
        cout << setw(15) << "Name: ";        
        getline(cin, emp[i].empName);
        cout << setw(15) << "Hourly Wage: " << "$";        
        cin >> emp[i].hrlyWge;
        cout << setw(15) << "Hours Worked: ";        
        cin >> emp[i].hrsWrkd;
        cout << endl;
        
        // Calculate earnings per employee
        emp[i].ttlPay = calcPay(emp[i].hrlyWge, emp[i].hrsWrkd);
        // Check for incorrect input
        while (emp[i].ttlPay <= 0)
        {
            // Error messsage. Correction
            cout << endl;
            cout << "The earnings of an employee must be a positive\n"
                    "value, greater than 0." << endl;
            totWgs = 0;
            cout << "Please enter a valid record: " << endl;
            // Re-read
            cin.clear();
            cin.ignore(1000,'\n');
            cout << setw(15) << "Employee # : " << empNum << endl;
            cout << setw(15) << "Name: ";        
            getline(cin, emp[i].empName);
            cout << setw(15) << "Hourly Wage: " << "$";        
            cin >> emp[i].hrlyWge;
            cout << setw(15) << "Hours Worked: ";        
            cin >> emp[i].hrsWrkd;
            cout << endl;
            // Recalculate 
            // Calculate earnings per employee
            emp[i].ttlPay = calcPay(emp[i].hrlyWge, emp[i].hrsWrkd);
        }
        // Display earnings
        cout << setw(15) << "Earnings" << endl;
        cout << emp[i].empName << ": $ " << emp[i].ttlPay << endl;
        cout << endl;
        // Calculate total wages paid out
        totWgs += emp[i].ttlPay;
        empNum++;  
    }
    // Deallocate memory
    delete []emp;
    cout << endl;
    cout << "Total amount paid this period: $" << totWgs << endl;
}

float calcPay (float hrlyWge, int hrsWrkd)
{
    int regTime = 0;             // Straight time hours
    int dblTime = 0;             // Double time hours
    int tplTime = 0;            // Triple time hours
    float totPay = 0;           // Total pay for employee
    
    // Check for double time
    if (hrsWrkd > 20 && hrsWrkd <= 40)
    {
        regTime = 20;
        dblTime = hrsWrkd - 20;
        tplTime = 0;       
    }
    // Check for triple time
    else if (hrsWrkd > 20 && hrsWrkd > 40)
    {
        regTime = 20;
        dblTime = 20;
        tplTime = hrsWrkd - 40;        
    }
    // Less than 20 hours
    else
    {
        regTime = hrsWrkd;
        dblTime = 0;
        tplTime = 0;
    }
    totPay = hrlyWge * (regTime + (2 * dblTime) + (3 * tplTime));
    // Return employee's total pay
    return totPay;   
}
