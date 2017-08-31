/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   build_sys_table.h
 * Author: vertika
 *
 * Created on 22 April, 2017, 7:35 PM
 */

#ifndef BUILD_SYS_TABLE_H
#define BUILD_SYS_TABLE_H

using namespace std;
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
#include <string>
#include <malloc.h>
#include <algorithm>
#include "agent.h"
#include "parser.h"

class BuildSystemTable {
public:
    vector<int> nextSum;
    vector<int> prevSum;

    BuildSystemTable();
    ~BuildSystemTable();
    int* calcIndices(int agNo, int stNo, int noOfStates);
    void calNextSum(System);
    void calPrevSum(System);

    void buildTable();

};



#endif /* BUILD_SYS_TABLE_H */

