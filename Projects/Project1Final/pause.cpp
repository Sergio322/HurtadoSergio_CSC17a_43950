#include "LibraryInc.h"
#include "AI.h"
#include "Player.h"

//2s delay for ai turn
void pause()
{
    time_t start, end;   //delay display ai fire 
    
    start = time(0);
    do
    {
        end = time(0);
    }while(difftime(end,start)<2);
}
