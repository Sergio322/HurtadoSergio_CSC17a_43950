#include "LibraryInc.h"
#include "AI.h"
#include "Player.h"

void init(PlayerB &pb,AIB &aib, int num, PlayerG &pG, PlayerS *ps, AIG &ai, AIS *as)
{
    fstream io;
    char temp;
    // Open unit file
    io.open("unit.txt", ios::in | ios::binary);
    if(io.is_open())
    {
        for(int i=0;i<5;i++)
        {
            io.read(&temp, sizeof(temp));
            pG.unit[i]=temp-48;
        }
        io.close();
    }
    //init by default
    else
    {
        cout<<"Default\n";
        for(int i=0;i<4;i++)
            pG.unit[i]=5-i;
        pG.unit[4]=2;
    }
    for(int i=0;i<4;i++)
        ai.cross[i]=true;
        ai.crossdone=true;
        ai.goback=true;
        ai.hx=10;
        ai.hy=10;
        ai.finish=true;
        ai.goback=true;
        ai.oppcombo=0;
        ai.combo=0;
        ai.oneend=false;
        as->hit=0;
        as->miss=0;
        ps->hit=0;
        ps->miss=0;
        
        //init table
        pb.pb = new char*[num];
        aib.fake = new char*[num];
        aib.real = new char*[num];
        for(int i=0;i<num;i++)
        {
            pb.pb[i] = new char[num];
            aib.fake[i] = new char[num];
            aib.real[i] = new char[num];
        }
        for(int i=0;i<num;i++)
        {
        for(int j=0;j<num;j++)
        {
            pb.pb[i][j]=' ';
            aib.fake[i][j]=' ';
            aib.real[i][j]=' ';
        }
    }
}
