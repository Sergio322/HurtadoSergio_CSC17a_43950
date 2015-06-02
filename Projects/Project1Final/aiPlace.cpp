#include "LibraryInc.h"
#include "Player.h"
#include "AI.h"
#include "Prototypes.h"

void aiplace(char **pb, char **fake, char **real, int unit[], int x1,int y1, int num)
{
    int count;
    int pos;
    bool valid;
    for(int q = 0;q < 5;q++)
    {
        do
        {
            valid = true;
            count = 0;
            //random coordinates
            y1 = rand()%(num-unit[q]);     //won't over size
            x1 = rand()%(num-unit[q]);
            pos = rand()%2;
            if(pos  ==  0)
            {                 //0 horizontal
                for(int k = y1;k < y1 + unit[q];k++)
                {
                    if(*(*(real+k)+x1)  ==  ' ')
                    {
                        count++;
                    }
                }
                if(count != unit[q])
                {
                    valid = false;
                }
                if(valid  ==  true)
                {
                    for(int k = y1; k < y1 + unit[q]; k++)
                    {
                        *(*(real+k) + x1) = unit[q]+48;
                    }
                }
            }
            else                    //1 vertical
            {                     
                for(int k = x1;k < x1 + unit[q];k++)
                {
                    if(real[y1][k]  ==  ' ')
                    {
                        count++;
                    }
                }
                if(count != unit[q])
                {
                    valid = false;
                }
                if(valid  ==  true)
                {
                    for(int k = x1;k < x1 + unit[q];k++)
                    {
                        real[y1][k] = unit[q]+48;
                    }
                }
            }
        }while(valid  ==  false);
    }
}
