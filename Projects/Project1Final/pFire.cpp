#include "LibraryInc.h"
#include "Player.h"
#include "AI.h"
#include "Prototypes.h"

int pfire(char **pb, char **fake, char **real, PlayerG &pG, PlayerS *ps, int num)
{
    string fire;                          //player fire;
    bool over = true;
    bool valid;
    do
    {
        valid = true;
        cout << "Your turn, please enter a coordinate to fire in A0 form :";
        cin >> fire;
        if(fire.length() != 2)
        {
            valid = false;
            cout << "size\n";
        }
        //fire[1]<'0' || fire[1]>'9' || 
        if(fire[0]<'A' || fire[0]>'J' || fire[1]<'0' || fire[1]>num+48-1)
        {
            valid = false;
            cout << "x/y\n";
        }
        pG.y1 = fire[0]-65;
        pG.x1 = fire[1]-48;
        if(real[pG.y1][pG.x1]  ==  'O' || real[pG.y1][pG.x1]  ==  'X')
        {
            valid = false;
            cout << "overlap\n";
        }
    }while(valid  ==  false);
    //hit
    if(real[pG.y1][pG.x1] >= '2' && real[pG.y1][pG.x1] <= '5')
    {     
        cout << "Hit!!!\n";
        real[pG.y1][pG.x1] = 'X';
        fake[pG.y1][pG.x1] = 'X';
        ps->hit++;
    }
    else
    {
        cout << "Miss....\n";
        real[pG.y1][pG.x1] = 'O';
        fake[pG.y1][pG.x1] = 'O';
        ps->miss++;
    }
    //board
    board(pb, fake, real, num);
    for(int i = 0;i<num;i++)
    {
        for(int j = 0;j<num;j++)
        {
            if(real[i][j] >= '2' && real[i][j] <= '5')
                over = false;
        }
    }
    if(over  ==  true)
    {
        return 3;
    }
    else
    {
        return 2;
    }
}
