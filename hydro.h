//
//  hydro.h
//  Lab8_C
//
//  Created by Alex Mclean on 2022-11-24.
//

#ifndef hydro_h
#define hydro_h

#include <stdio.h>
using namespace std;
#include "list.h"
#include <fstream>

FlowList x;
void displayHeader();
void pressEnter();

int readData(FlowList& x);
int menu();
void display(FlowList& x);
// calls function avg
double average(double c, int i);

int addData(FlowList &x, int numRecords);
void removeData(FlowList &x);
void saveData(FlowList &x);

#endif /* hydro_h */
