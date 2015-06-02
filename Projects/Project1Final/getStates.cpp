#include "LibraryInc.h"
#include "AI.h"
#include "Player.h"

void getstates(PlayerS *ps)
{
    fstream io;
    float pbtl = 0; //total fire
    float pac;     //accuracy
    char pr;        //player rank
    pbtl = ps->hit + ps->miss;
    pac = (ps->hit) / pbtl;
    if(pac>90) pr = 'S';
    else if(pac>80) pr = 'A';
    else if(pac>70) pr = 'B';
    else if(pac>60) pr = 'C';
    else if(pac>50) pr = 'D';
    else if(pac>40) pr = 'E';
    else pr = 'F';
    io.open("rank.txt", ios::out | ios::binary);
    if(io.fail())
        cout << "Open fail\n";
    else
    {
        char m1[] = {'R', 'a', 'n', 'k', '='};
        io.write(m1, sizeof(m1));
        io.write(&pr,sizeof(pr));
        io.close();
    }
}
