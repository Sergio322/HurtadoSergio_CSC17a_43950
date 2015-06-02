#include "LibraryInc.h"
#include "AI.h"
#include "Player.h"

void board(char **pb, char **fake, char **real, int num)
{
    //board
    //space 38, 3
    cout << "   PLAYER 1"<<setw(num*4+4) << "A.I.\n";
    for(int i=0;i<num;i++)
    {
        cout<<setw(4)<<i;
    }
    cout<<"       ";
    for(int i=0;i<num;i++)
    {
        cout<<setw(4)<<i;
    }
    cout<<endl;
    //third line
    cout<<"  ";
    for(int i=0;i<num;i++)
    {
        cout<<"____";
    }
    cout<<"      ";
    for(int i=0;i<num;i++)
    {
        cout<<"____";
    }
    cout<<endl;
    //forth to num line
    for(int i=0;i<num;i++)
    {
        char row=i+65;
        cout<<row<<"| ";
        for(int j=0;j<num;j++)
        {
            cout<<pb[i][j];
            cout<<" "<<"| ";
        }
        cout<<"    "<<"| ";
        
        for(int k=0;k<num;k++)
        {
            cout<<fake[i][k];
            cout<<" "<<"| ";
        }
        cout<<endl;
        cout<<"  ";
        for(int l=0;l<num;l++)
        {
           cout<<"----";
        }
        cout<<"      ";
        for(int m=0;m<num;m++)
        {
           cout<<"----";
        }
        cout<<endl;
    }
}
