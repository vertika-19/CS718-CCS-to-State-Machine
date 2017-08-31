/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   agent_table.h
 * Author: vertika
 *
 * Created on 22 April, 2017, 1:21 AM
 */

#ifndef AGENT_TABLE_H
#define AGENT_TABLE_H

using namespace std;
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
#include <string>
#include "agent.h"
#include "parser.h"

class BuildAgentTable {
    
    public :
        vector<Agent> *ptrVecAgents;
     
        vector<string> *ptrAgentExprs;
        
        BuildAgentTable();
        ~BuildAgentTable();
        void buildTable();
    
    
};


#endif /* AGENT_TABLE_H */

