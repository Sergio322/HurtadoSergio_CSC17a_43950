#include "Problem6.h"

void soltn6()
{
    // 2.125
    cout << left;
    cout << "Number: 2.125" << endl;
    cout << setw(15) << "Base 2" << setw(15) << "Base 8" << setw(15)
         << "Base 16" << endl;
    cout << setw(15) << "10.001" << setw(15) << "2.02" << setw(15)
         << "2.2" << endl;
    cout << endl;
    // 0.06640625
    cout << "Number: 0.06640625" << endl;
    cout << setw(15) << "Base 2" << setw(15) << "Base 8" << setw(15)
         << "Base 16" << endl;
    cout << setw(15) << "0.00010001" << setw(15) << "0.042" << setw(15)
         << "0.11" << endl; 
    cout << endl;
    
    // -2.125 to float
    cout << left;
    cout << "Number: -2.125 in Float represantation: " << endl;
    cout << "10111000010100011110110001111001" << endl;
    cout << endl;
    // 0.06640625
    cout << "Number: 0.06640625 in Float representation: " << endl;
    cout << "01000100000000000000000010000011" << endl;
    cout << endl;
    
    // Float to decimal
    cout << "Number: 46666601 to decimal: 1.099999904632568" << endl;
    cout << "Number: 46666602 to decimal: 2.199999809265136" << endl;
    cout << "Number: B9999AFE to decimal: -4.43734 x 10e-32" << endl;
}
