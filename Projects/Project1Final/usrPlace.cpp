#include "LibraryInc.h"
#include "Player.h"
#include "AI.h"
#include "Prototypes.h"

void usrPlce(char **pb, char **fake, char **real, PlayerG &pG, int num)
{
    int count;
    int max;
    int min;
    string place;
    bool valid;
    bool digit;
    //place ship
    for(int q = 0;q<5;q++)
    {
        do
        {
            do
            {
                do
                {
                    count = 0;
                    digit = false;
                    valid = true;   //reset
                    cout << "Choose the coordinates to place the ";
                    cout << pG.unit[q] << "-unit ship in A1A5 format : ";
                    cin >> place;
                    if(place.size() != 4)     //check size
                    {        
                        cout << "size\n";
                        valid = false;
                    }
                    digit = false;
                    if(isdigit(place[1]) && isdigit(place[3]))
                    {
                        digit = true;
                    }
                    if(place[0]<'A' || place[0]>'J' || place[2]<'A' || place[2]>'J')
                    {
                        valid = false;
                    }
                    if(valid  ==  false || digit  ==  false)
                    {
                        cout << "Invalid input\n";
                    }
                }while(valid  ==  false || digit  ==  false);
                cout << place[0]-65 << place[1]-48 << place[2]-65 << place[3]-48 << endl;
                pG.y1 = place[0]-65;
                pG.y2 = place[2]-65;
                pG.x1 = place[1]-48;
                pG.x2 = place[3]-48;
                cout << pG.y1 << pG.x1 << pG.y2 << pG.x2 << endl;
                if(pG.y1  ==  pG.y2)                        //x is same
                {     
                    if(abs(pG.x1-pG.x2) != pG.unit[q]-1) //check unit invalid
                    {  
                        cout << "x unit\n";
                        valid = false;
                    }
                    else                        //valid
                    {                  
                        if(pG.x1>pG.x2)         //check which larger
                        {       
                            max = pG.x1;
                            min = pG.x2;
                        }
                        else
                        {
                            max = pG.x2;
                            min = pG.x1;
                        }
                        cout << "max = " << max << endl;
                        cout << "min = " << min << endl;
                        cout << "p" << pG.y1 << endl;
                        for(int k = min;k <= max; k++)   //check overlap
                        {
                            if(*(*(pb+pG.y1)+k)  ==  ' ')
                            {
                                count++;
                            }
                        }
                        if(count != pG.unit[q])
                        {
                            valid = false;
                            cout << "overlap\n";
                        }
                        if(valid  ==  true)
                        {
                            for(int k = min;k <= max;k++)
                            {
                                *(*(pb+pG.y1)+k) = pG.unit[q]+48;
                            }
                        }
                    }
                }
                if(pG.x1  ==  pG.x2)                          //y is same
                {          
                    if(abs(pG.y1-pG.y2) != pG.unit[q]-1)    //check unit
                    {   
                        cout << "y unit\n";
                        valid = false;
                    }
                    else                                  //valid
                    {           
                        if(pG.y1>pG.y2)
                        {
                            max = pG.y1;
                            min = pG.y2;
                        }
                        else
                        {
                            max = pG.y2;
                            min = pG.y1;
                        }
                        cout << "max = " << max << endl;
                        cout << "min = " << min << endl;
                        cout << "p" << pG.y1 << endl;
                        for(int k = min;k <= max;k++)
                        {
                            if(*(*(pb+k)+pG.x1)  ==  ' ')
                            {
                                count++;
                            }
                        }
                        if(count != pG.unit[q])
                        {
                            valid = false;
                            cout << "overlap\n";
                        }
                        if(valid  ==  true)
                        {
                            for(int k = min;k <= max;k++)
                            {
                                *(*(pb+k)+pG.x1) = pG.unit[q]+48;
                            }
                        }
                    }
                }
                if(pG.x1 != pG.x2 && pG.y1 != pG.y2)
                {
                    valid = false;
                    cout << "horizontal/vertical\n";
                }
            }while(valid  ==  false);
            cout << count << endl;
        }while(valid  ==  false);
        cout << "\n\n\n\n\n\n\n\n\n";
    //board
    board(pb, fake, real, num);
    }
}

