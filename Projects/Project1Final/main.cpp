/* 
 * File:   main.cpp
 * Author: Sergio Hurtado
 *
 * Created on April 22, 2015, 8:03 AM
 */

//User Libraries
#include "LibraryInc.h"
#include "Player.h"
#include "AI.h"

//Global Constants

//Prototypes
#include "Prototypes.h"

//Execution begins here
int main(int argc, char** argv) 
{
    intro();
    int num = getNum();
    int turn = 1;
    int over;
    PlayerB pb;
    PlayerG pG;
    PlayerS *ps  =  new PlayerS;
    AIB aib;
    AIG ai;
    AIS *as  =  new AIS;
    cout << fixed << showpoint << setprecision(2);

    //reset
    srand(static_cast<unsigned int>(time(0)));
    init(pb, aib, num, pG, ps, ai, as);
    board(pb.pb, aib.fake, aib.real, num);
    //player prepare
    usrPlce(pb.pb, aib.fake, aib.real, pG, num);
    aiplace(pb.pb, aib.fake, aib.real, pG.unit, pG.x1, pG.y1, num);
    //game start
    do
    {
        switch(turn)
        {
            case 1:
            {
                turn = pfire(pb.pb, aib.fake, aib.real, pG, ps, num);
                break;
            }
            case 2:
            {
                turn = aifire(pb.pb, aib.fake, aib.real, ai, as, num);
                break;
            }
            case 3:
            {
                cout << "You win!\n\n";turn = 5;
                break;
            }
            case 4:
            {
                cout << "You lose!\n\n";turn = 5;
                break;
            }
        }
    }while(turn<5);
    getstates(ps);
    //free memory
    for (int i = 0;i<num;i++)
    {
         delete[] pb.pb[i];
         delete[] aib.real[i];
         delete[] aib.fake[i];
    }    
    delete[] pb.pb;
    delete[] aib.real;
    delete[] aib.fake;
    delete ps, as;
    return 0;
}
