/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gen_output.h
 * Author: vertika
 *
 * Created on 24 April, 2017, 4:35 PM
 */

#ifndef GEN_OUTPUT_H
#define GEN_OUTPUT_H
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "parser.h"

class GenFSM {
    
    public:
        GenFSM();
        ~GenFSM();
        void writeAgentFiles(Agent *ptrAgent);
        void writeSystemFiles(System *ptrSys);
        void process();
        void createDot(char *,char );
};

#endif /* GEN_OUTPUT_H */

