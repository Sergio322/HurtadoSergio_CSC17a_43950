/* 
 * File:   AI.h
 * Author: Sergio Hurtado
 *
 * Created on April 20, 2015, 6:45 PM
 */

#ifndef AI_H
#define	AI_H
struct AIB
{
    char **fake;
    char **real;
};

struct AIG
{
    bool over;
    bool done;
    bool cross[4];
    bool crossdone;
    bool goback;
    int hx, hy, x, y;
    bool finish;
    int oppcombo;
    int combo;
    char cx, cy;
    bool hit;
    bool oneend;
    bool combohit;
};

struct AIS
{
    float miss;
    float hit;
};


#endif	/* AI_H */
