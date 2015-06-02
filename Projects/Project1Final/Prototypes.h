/* 
 * File:   Prototypes.h
 * Author: Sergio
 *
 * Created on April 23, 2015, 2:57 PM
 */

#ifndef PROTOTYPES_H
#define	PROTOTYPES_H

//Function Prototypes
void intro();
int getNum();
void pause();
void init(PlayerB &, AIB &,  int, PlayerG &, PlayerS *, AIG &, AIS *);
void board(char **, char **, char **, int);
void usrPlce(char **, char **, char **, PlayerG &, int);
void aiplace(char **, char **, char **, int [], int, int, int);
int pfire(char **, char **, char **, PlayerG &, PlayerS *, int);
int aifire(char **, char **, char **, AIG &, AIS *, int);
void getstates(PlayerS *);

#endif	/* PROTOTYPES_H */
