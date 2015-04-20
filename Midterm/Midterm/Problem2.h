/* 
 * File:   problem2.h
 * Author: Sergio Hurtado
 * Description: Header file for problem 2
 * Created on April 10, 2015, 2:45 PM
 */

#ifndef PROBLEM2__H
#define	PROBLEM2__H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct PayStmt
{
    string empName;             // Employee name
    int hrsWrkd;                // Total hours worked
    float hrlyWge;              // Employee's hourly wage
    float ttlPay;               // Employee's total pay
};

void soltn2();
void getEmp(PayStmt* &emp, int i, int &count);
float calcPay(float hrlyWge, int hrsWrkd);

#endif	/* PROBLEM2__H */

