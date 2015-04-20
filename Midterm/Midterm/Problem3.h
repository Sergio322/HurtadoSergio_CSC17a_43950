/* 
 * File:   problem3.h
 * Author: Sergio Hurtado
 * Description: Header file for problem 3
 * Created on April 11, 2015, 8:09 PM
 */

#ifndef PROBLEM3_H
#define	PROBLEM3_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "MidtermHeader.h"

using namespace std;

//Structure for Probelm 3
struct statsResult
{
    float avg;
    float median;
    int *mode;
    int nModes;
    int maxFreq;
};

void soltn3();
statsResult *avgMedMode(int *, int);
void printStat(statsResult *);
void plcmnt(int *, int);

#endif	/* PROBLEM3_H */

