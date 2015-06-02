#include "LibraryInc.h"
#include "Player.h"
#include "AI.h"
#include "Prototypes.h"

int aifire(char **pb, char **fake, char **real, AIG &ai, AIS *as, int num)
{
    srand(static_cast<unsigned int>(time(0)));
    cout << "aifire\n";
    pause();
    int turn;
    bool valid;
    int hplan;
    ai.over = true;
    ai.done = false;
    for(int i = 0;i<4;i++)
    {
        ai.cross[i] = true;
    }
    do{
        ai.done = false;
        if(ai.crossdone  ==  true && ai.finish  ==  true && ai.goback  ==  true 
           && ai.done  ==  false && ai.oppcombo  ==  0 && ai.combo  ==  0)
        {
            //random fire
//            cout << "random fire\n";
            ai.goback = true;
            do
            {
                valid = true;
                ai.x = rand()%num;
                ai.y = rand()%num;
                if(pb[ai.y][ai.x]  ==  'O' || pb[ai.y][ai.x]  ==  'X')
                {
                    valid = false;
                    cout << "overlap\n";
                }
            }while(valid  ==  false);
            ai.cx = ai.x+48;
            ai.cy = ai.y+65;
            cout << "ai fire " << ai.cy << ai.cx << "\n";
            if(pb[ai.y][ai.x] != ' ')
            {
                pb[ai.y][ai.x] = 'X';
                cout << "Hit!!!\n";
                ai.hx = ai.x;
                ai.hy = ai.y;
                ai.hit = true;
                ai.crossdone = false;
                ai.finish = false;
                ai.combo = false;
                ai.done = true;
                ai.oneend = false;
                as->hit++;
            }
            else
            {
                pb[ai.y][ai.x] = 'O';
                cout << "Miss...\n";
                ai.done = true;
                as->miss++;
            }
        }

        //move after hit
        if(ai.hit  ==  true && ai.finish  ==  false && ai.crossdone  ==  false 
           && ai.combo  ==  0 && ai.oppcombo  ==  0 && ai.done  ==  false)
        {
            do
            {
                ai.y = ai.hy;
                ai.x = ai.hx;
                //check cross rand
                hplan = rand()%4;
                if(hplan  ==  0) ai.y = ai.hy-1;
                if(hplan  ==  1) ai.y = ai.hy+1;
                if(hplan  ==  2) ai.x = ai.hx-1;
                if(hplan  ==  3) ai.x = ai.hx+1;
                cout << "hplan  =  " << hplan << endl;
                //check over size
                if(ai.y<0 || ai.y>num-1 || ai.x<0 || ai.x>num-1)
                {
                    ai.cross[hplan] = false;
                }
                else if(pb[ai.y][ai.x]  ==  'X' || pb[ai.y][ai.x]  ==  'O')
                {
                    ai.cross[hplan] = false;
                }
                if(ai.cross[0]  ==  ai.cross[1] && ai.cross[1]  ==  ai.cross[2] 
                   && ai.cross[2]  ==  ai.cross[3] && ai.cross[0]  ==  false)
                {
                    ai.crossdone = true;
                    ai.finish = true;
                    ai.goback = true;
                }
            }while(ai.crossdone  ==  false && ai.cross[hplan]  ==  false);

            //valid
            if(ai.crossdone  ==  false)
            {
                ai.cx = ai.x+48;
                ai.cy = ai.y+65;
                cout << "ai fire " << ai.cy << ai.cx << "\n";
                if(pb[ai.y][ai.x] != ' ')
                {
                    pb[ai.y][ai.x] = 'X';
                    cout << "Hit!!!\n";
                    ai.done = true;
                    ai.combo++;
                    ai.crossdone = true;
                    as->hit++;
                }
                else
                {
                    pb[ai.y][ai.x] = 'O';
                    cout << "Miss...\n";
                    ai.done = true;
                    as->miss++;
                }
            }
            else
            {
                ai.goback = true;
            }
        }
        else if(ai.combo>0 && ai.oneend  ==  false && ai.done  ==  false &&
                ai.crossdone  ==  true)     //continue check
        {   
            valid = true;
            if(ai.hx  ==  ai.x)
            {
                if(ai.hy>ai.y) ai.y = ai.hy-ai.combo-1;
                else           ai.y = ai.hy+ai.combo+1;
                if(ai.y<0 || ai.y >9)
                {
                    valid = false;
                }
                if(valid  ==  true)
                {
                    if(pb[ai.y][ai.x]  ==  'X' || pb[ai.y][ai.x]  ==  'O')
                    {
                        valid = false;
                    }
                    if(pb[ai.y][ai.x]  ==  'O')
                    {
                        ai.finish = true;
                        ai.goback = true;
                        ai.crossdone = true;
                        ai.combo = 0;
                    }
                    if(valid  ==  true)
                    {
                        ai.cx = ai.x+48;
                        ai.cy = ai.y+65;
                        cout << "ai fire " << ai.cy << ai.cx << "\n";
                        if(pb[ai.y][ai.x] != ' ')
                        {
                            pb[ai.y][ai.x] = 'X';
                            cout << "Hit!!!\n";
                            ai.done = true;
                            ai.combo++;
                            as->hit++;
                        }
                        else
                        {
                            pb[ai.y][ai.x] = 'O';
                            cout << "Miss...\n";
                            ai.done = true;
                            ai.oneend = true;
                            ai.oppcombo++;
                            as->miss++;
                        }
                    }
                }
                else        //check ->GO TO OPPCOMBO
                {
                    ai.combo = 0;
                    ai.oneend = true;
                    ai.crossdone = true;
                    ai.oppcombo++;
                    ai.combohit = false;
                }
            }
            if(ai.hy  ==  ai.y)
            {
                if(ai.hx>ai.x) ai.x = ai.hx-ai.combo-1;
                else ai.x = ai.hx+ai.combo+1;
                if(ai.x<0 || ai.x >9)
                {
                    valid = false;
                    ai.combo = 0;
                    ai.goback = true;
                    ai.finish = true;
                }
                if(valid  ==  true)
                {
                    if(pb[ai.y][ai.x]  ==  'X' || pb[ai.y][ai.x]  ==  'O')
                    {
                        valid = false;
                        ai.finish = true;
                        ai.goback = true;
                    }
                    if(valid  ==  true)
                    {
                        ai.cx = ai.x+48;
                        ai.cy = ai.y+65;
                        cout << "ai fire " << ai.cy << ai.cx << "\n";
                        if(pb[ai.y][ai.x] != ' ')
                        {
                            pb[ai.y][ai.x] = 'X';
                            ai.combo++;
                            ai.done = true;
                            as->hit++;
                        }
                        else
                        {
                            pb[ai.y][ai.x] = 'O';
                            cout << "Miss...\n";
                            ai.done = true;
                            ai.oneend = true;
                            ai.oppcombo++;
                            ai.combo = 0;
                            ai.combohit = false;
                            as->miss++;
                        }
                    }
                }
                if(valid  ==  false)        //GO TO OPPCOMBO
                { 
                    ai.combo = 0;
                    ai.oneend = true;
                    ai.crossdone = true;
                    ai.oppcombo++;
                    ai.combohit = false;
                }
            }
        }
        else if(ai.oppcombo>0 && ai.oneend  ==  true && ai.done  ==  false) //check other side
        {
            if(ai.hx  ==  ai.x)
            {
                if(ai.combohit  ==  false)
                {
                    if(ai.hy>ai.y) ai.y = ai.hy+ai.oppcombo;
                    else ai.y = ai.hy-ai.oppcombo;
                }
                else
                {
                    if(ai.y>ai.hy) ai.y = ai.hy+ai.oppcombo;
                    else ai.y = ai.hy-ai.oppcombo;
                }
                        cout << ai.y << ai.x << endl;
                if(ai.y<0 || ai.y>num-1 || pb[ai.y][ai.x]  ==  'O' 
                          || pb[ai.y][ai.x]  ==  'X')
                {
                    ai.oppcombo = 0;
                    ai.goback = true;
                    ai.finish = true;
                    ai.crossdone = true;
                    ai.combo = 0;
                    ai.done = false;
                }
                else
                {
                    ai.cx = ai.x+48;
                    ai.cy = ai.y+65;
                    cout << "ai fire " << ai.cy << ai.cx << "\n";
                    if(pb[ai.y][ai.x] != ' ')
                    {
                        pb[ai.y][ai.x] = 'X';
                        cout << "Hit!!!\n";
                        ai.done = true;
                        ai.oppcombo += 1;
                        ai.combohit = true;
                        as->hit++;
                    }
                    else
                    {
                        pb[ai.y][ai.x] = 'O';
                        cout << "Miss...\n";
                        ai.done = true;
                        ai.combo = 0;
                        ai.oppcombo = 0;
                        ai.finish = true;
                        ai.goback = true;
                        ai.crossdone = true;
                        as->miss++;
                    }
                }
            }
            else if(ai.hy  ==  ai.y)
            {
                if(ai.combohit  ==  false)
                {
                    if(ai.hx>ai.x) ai.x = ai.hx+ai.oppcombo;
                    else ai.x = ai.hx-ai.oppcombo;
                }
                else
                {
                    if(ai.x>ai.hx) ai.x = ai.hx+ai.oppcombo;
                    else ai.x = ai.hx-ai.oppcombo;
                }
                if(ai.x<0 || ai.x>num-1 || pb[ai.y][ai.x]  ==  'O' 
                          || pb[ai.y][ai.x]  ==  'X')
                {
                    ai.oppcombo = 0;
                    ai.goback = true;
                    ai.finish = true;
                    ai.crossdone = true;
                    ai.combo = 0;
                    ai.done = false;
                }
                else
                {
                    ai.cx = ai.x+48;
                    ai.cy = ai.y+65;
                    cout << "ai fire " << ai.cy << ai.cx << "\n";
                    if(pb[ai.y][ai.x] != ' ')
                    {
                        pb[ai.y][ai.x] = 'X';
                        cout << "Hit!!!\n";
                        ai.done = true;
                        ai.oppcombo += 1;
                        ai.combohit = true;
                        as->hit++;
                    }
                    else
                    {
                        pb[ai.y][ai.x] = 'O';
                        cout << "Miss...\n";
                        ai.done = true;
                        ai.combo = 0;
                        ai.oppcombo = 0;
                        ai.finish = true;
                        ai.goback = true;
                        ai.crossdone = true;
                        as->miss++;
                    }
                }
            }
        }
    }while(ai.done  ==  false);

    for(int i = 0;i<num;i++)
    {    //check over
        for(int j = 0;j<num;j++)
        {
            if(pb[i][j] >= '2' && pb[i][j] <= '5')
                ai.over = false;
        }
    }
    if(ai.over  ==  false) turn = 1;
    else turn = 4;
    //board
    board(pb, fake, real, num);
    return turn;
}
