#include "LibraryInc.h"

int getNum()
{
    int n;
    bool invalid=false;
    do
    {
        cout<<"Please choose the size of the table (8-10) :";
        cin>>n;
        if(n<8 || n>10)
            invalid=true;
    }while(invalid);
    return n;
}
