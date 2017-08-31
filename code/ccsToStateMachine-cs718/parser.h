/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   parser.h
 * Author: vertika
 *
 * Created on 21 April, 2017, 10:25 PM
 */

#ifndef PARSER_H
#define PARSER_H

using namespace std;


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include "system.h"
#include "agent.h"
#include "rcv_input.h"
    
class Parser {
    public :
        vector< Agent > agents;
        vector< System > systems;
        map<char,Agent> mapAgentNameToObj;
        
    public :
        Parser();
        ~Parser();
    
    public:
       void addAgents(string);
       void addSystem(string);
       void process();
        
};


#endif /* PARSER_H */

