/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rcv_input.h
 * Author: vertika
 *
 * Created on 21 April, 2017, 10:26 PM
 */

#ifndef RCV_INPUT_H
#define RCV_INPUT_H

using namespace std;

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

class RcvInput {
    public:
        vector< string > agentExp;
        RcvInput();
        ~RcvInput();
        
    public:
        void readFile(char* );
        
};
#endif /* RCV_INPUT_H */

