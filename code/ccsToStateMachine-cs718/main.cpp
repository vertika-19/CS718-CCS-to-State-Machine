/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: vertika
 *
 * Created on 21 April, 2017, 10:05 PM
 */

#include <cstdlib>

#include "parser.h"
#include "rcv_input.h"
#include "build_agent_table.h"
#include "build_sys_table.h"
#include "gen_output.h"

using namespace std;

/*
 * 
 */

extern Parser parserObj;
extern RcvInput rcvInputObj;
extern BuildAgentTable agentTableObj;
extern BuildSystemTable buildSystemTableObj;
extern GenFSM genFsmObj;

int main(int argc, char** argv) {
    
    //default file name
    char filename[] = "input.txt";
    rcvInputObj.readFile(filename);
    
//    if( argc < 2 ) {
//        //perror("Insufficient arguments");
//        //exit(1);
//    }
//    
    if(argc > 2 ) 
        sprintf(filename,"%s",argv[1]);
    
    cout << filename << endl;
    
    for( int i = 0; i < rcvInputObj.agentExp.size();i++) {
        cout << rcvInputObj.agentExp[i] << endl;
    }
    parserObj.process();
    cout << "Input Parsed"<< endl;
    agentTableObj.buildTable();
    cout << "Agent tables built "<< endl;
    buildSystemTableObj.buildTable();
    cout << "System tables built "<< endl;
    genFsmObj.process();
    cout << "Files generated" << endl;
    
    return 0;
}

