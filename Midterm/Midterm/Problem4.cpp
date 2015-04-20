/*  Problem 4:
 
    A company wants to transmit data over the telephone, but they are 
    concerned that their phones may be tapped. All of their data is 
    transmitted as four-digit integers. However, they utilize the digits 
    0,1,2,3,4,5,6,7 only. They have asked you to write a program that 
    will encrypt their data so that it may be transmitted more securely.
    Your application should read a four-digit integer with the numbers 
    0 to 7 entered by the user in an input dialog and encrypt it as 
    follows: Replace each digit by (the sum of that digit plus 3) modulus 8. 
    Then swap the first digit with the second, and swap the third digit 
    with the fourth. Then print the encrypted integer. Write a separate 
    application that inputs an encrypted four-digit integer and decrypts 
    it to form the original number.
    Note:  sometimes errors occur and the digits 8, and 9 might appear.  
    Detect this condition and flag the error.  Can't read in numbers 
    individually.  All the digits must be read with one cin statement.
 */

#include "Problem4.h"

void soltn4() 
{
    char **ptr;                 // Pointer to pointer of chars
    char chrStor;               // Hold chars temporarily
    int rows = 0;               // For manipulation of numbers
    int i = 0;                  // Loop variables
    int j = 0;
    bool valid = false;         // Initialize valid to false
    int **intPtr;               // Pointer to pointer of ints
    // How many integers are we encrypting?
    cout << "Number of four digit integers you wish to encrypt: " << endl;
    cin >> rows;
    cout << endl;
    ptr = new char*[rows];
    // Allocate memory for integers to encrypt
    for (i = 0; i < rows; i++)
    {
        ptr[i] = new char[4];
    }
    // Clear buffer
    cin.clear();
    cin.ignore(1000, '\n');
    
    // Get integers to be encrypted
    cout << "Please enter the integers to be encrypted." << endl; 
    cout << "Only 4 digit integers from 1-7 allowed:" << endl;
    getAray(ptr,rows);
    // Create pointer to manipulate the integers
    intPtr = new int*[rows];
    for (i = 0; i < rows; i++)
    {
        intPtr[i] = new int[4];
    }
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < 4; j++) 
        {
            chrStor = ptr[i][j];
            intPtr[i][j] = ((int)chrStor - 48);
        }
    }
    // Deallocate memory
    for (i = 0; i < rows; i++) 
    {
        delete []ptr[i];
    }
    delete []ptr;
    
    // Encrypt and decrypt
    encrypt(intPtr,rows);
    decrypt(intPtr,rows);

    // Deallocate memory
    for (i = 0; i < rows; i++) 
    {
        delete []intPtr[i];
    }
    delete []intPtr;
}

// encrypt function
void encrypt(int** &ptr, int rows) 
{
    int i = 0;          // Loop control
    int j = 0;
    int num1 = 0;       // Hold first number
    // See ptr before
    cout << endl;
    cout << left;
    cout << setw(16) << "Encrypting: " <<  endl;
    // Display input
    cout << setw(16) << "Original: ";
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < 4; j++) 
        {
            cout << ptr[i][j];
        }
        cout << " | ";
        // First step, Replace each by (itself + 3) % 8 
        for (j = 0; j < 4; j++) 
        {
            ptr[i][j] = (ptr[i][j] + 3) % 8;
        }
        // Second step, swap values
        num1 = ptr[i][0];
        ptr[i][0] = ptr[i][1];
        ptr[i][1] = num1;    
        num1 = ptr[i][2];
        ptr[i][2] = ptr[i][3];
        ptr[i][3] = num1;
    }
    cout << endl;
    // Print encrypted integer
    cout << setw(16) << "Encrypted: ";
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < 4; j++) 
        {
            cout << ptr[i][j];
        }
        cout << " | ";
    }
    cout << endl;
}

// decrypt function
void decrypt(int** &ptr, int rows) 
{
    int i = 0;              // Loop control
    int j = 0;
    int num1 = 0;           // Hold number for decrypting
    
    cout << endl;
    cout << left;
    cout << setw(16) << "Decrypting:" << endl;
    // Display decrypted number
    cout << setw(16) << "Encrypted: ";
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < 4; j++) 
        {
            cout << ptr[i][j];
        }
        cout << " | ";
        for (j = 0; j < 4; j++) 
        {
            // All possibilities
            switch (ptr[i][j]) 
            {
                case 0: ptr[i][j] = 5;break;
                case 1: ptr[i][j] = 6;break;
                case 2: ptr[i][j] = 7;break;
                case 3: ptr[i][j] = 8;break;
                case 4: ptr[i][j] = 1;break;
                case 5: ptr[i][j] = 2;break;
                case 6: ptr[i][j] = 3;break;
                case 7: ptr[i][j] = 4;break;
                case 8: cout << "Error!"; return;
                case 9: cout << "Error!"; return;
            }
        }
        // Swap values accordingly
        num1 = ptr[i][0];
        ptr[i][0] = ptr[i][1];
        ptr[i][1] = num1;    
        num1 = ptr[i][2];
        ptr[i][2] = ptr[i][3];
        ptr[i][3] = num1; 
    }
    cout << endl;
    // Display decrypted value
    cout << setw(16) << "Decrypted: ";
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < 4; j++) 
        {
            cout << ptr[i][j];
        }
        cout << " | ";
    }
    cout << endl;
}

// getAray function
void getAray(char** &ptr, int rows) 
{
    int i = 0;                  // Loop control
    int j = 0;
    int counter = 1;            // Keep track of input
    bool valid = true;          // Check for valid input
    // Get array from user
    for (i = 0; i < rows; i++) 
    {
        do 
        {
            cin.clear();
            cout << "Input integer # " << counter << ": ";
            cin.getline(ptr[i],1000);
            j = cin.gcount();

            // Error checking for only 4 digits plus null
            if (j > 5) 
            {
                cout << "Input is invalid! Please try again: ";
                valid = false;
            }
            else (valid = true);
            for (j = 0; j <= 5; j++) 
            {
                // Check if input is 8, 9 or 0
                if( ptr[i][j] == '8' || 
                    ptr[i][j] == '9' || 
                    ptr[i][j] == '0' ) 
                {
                    cout << "Input is invalid! Please use numbers 1-7:" << endl;
                    valid = false;
                    j = 5;
                }
                else(valid = true);
            }
            // Make sure input is digits
            for (j = 0; j < 4; j++) 
            {
                if (!isdigit(ptr[i][j])) 
                { 
                    valid = false;
                    cout << "Input is invalid! Please try again: " << endl;
                    j = 5;
                }
            }
        } while (!valid);
        // If all is well
        cout << "Integer: " << counter << " is: " << ptr[i] << endl;   
        counter++;
    }
}
