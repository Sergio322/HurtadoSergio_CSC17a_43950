#include "LibraryInc.h"

void intro()
{
    fstream io;
    io.open("intro.txt", ios::in);
    if(io.is_open())
    {
        string temp;
        while(getline(io, temp))
            cout<<temp<<endl;
        io.close();
    }
}
