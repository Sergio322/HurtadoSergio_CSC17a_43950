/* 
 * File:   problem4.h
 * Author: Sergio Hurtado
 * Description: Header file for problem 4
 * Created on April 12, 2015, 1:09 AM
 */

#ifndef PROBLEM4_H
#define	PROBLEM4_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include "MidtermHeader.h"
using namespace std;

void soltn4();
void encrypt(int** &ptr, int rows);
void decrypt(int** &ptr, int rows);
void getAray(char** &ptr, int rows);

#endif	/* PROBLEM4_H */
