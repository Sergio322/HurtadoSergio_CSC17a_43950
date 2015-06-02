/* 
 * File:   Player.h
 * Author: Sergio Hurtado
 *
 * Created on April 20, 2015, 7:56 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

struct PlayerB
{
    char **pb;
};
struct PlayerG
{
    int unit[5];
    int x1, x2, y1, y2;
};
//Status
struct PlayerS
{
    float hit;
    float miss;
};
#endif	/* PLAYER_H */
