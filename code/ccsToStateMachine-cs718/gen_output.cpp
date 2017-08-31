/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "gen_output.h"
#include "parser.h"


using namespace std;

extern Parser parserObj;

GenFSM genFsmObj;

GenFSM::GenFSM() {
    
}

GenFSM::~GenFSM() {
    
}




void GenFSM::writeAgentFiles(Agent *ptrAgent) {
    ofstream ofs;
    char agName = ptrAgent->name;
    char fname[10];
    sprintf(fname,"%c.txt",agName);
    ofs.open (fname, ofstream::out);
    if( ofs.is_open() ) {
        
        for( int i = 0;i< ptrAgent->noOfStates;i++) {
            for( int j = 0 ;j < ptrAgent->noOfStates; j++ ){
                
                if( !( (ptrAgent->table)[i][j]).empty() ) {
                    ofs << agName << i << "\t" << agName << j << "\t" << (ptrAgent->table)[i][j] << "\n";
                }
            }
        }
    }
    ofs.close();
    cout << "File for agent " << agName << " written successfully " << endl;   
    
}

void GenFSM::writeSystemFiles(System *ptrSys) {
    ofstream ofs;
    char sysName = ptrSys->name;
    char fname[10];
    sprintf(fname,"%c.txt",sysName);
    ofs.open (fname, ofstream::out);
    if( ofs.is_open() ) {
        
        for( int i = 0;i< ptrSys->noOfStates;i++) {
            for( int j = 0 ;j < ptrSys->noOfStates; j++ ){
                
                string str = (ptrSys->table)[i][j];
                if( !str.empty()  &&  str != "N" ) {
                    
                    size_t index = (ptrSys->restriction).find(str[0] ); 
                    if( str == "tau" || index == string::npos ) {
                        ofs << sysName << i << "\t" << sysName << j << "\t" << str << "\n";
                    }
                }
            }
        }
    }
    ofs.close();
    cout << "File for agent " << sysName << " written successfully " << endl;
}

void GenFSM::createDot(char *fname,char agname) {
 
    ofstream ofs;
    char filename[80];
    sprintf(filename,"%c.dot",agname);
    ofs.open (filename, ofstream::out);
    
    ifstream in(fname);
    
    if(!in) 
    {
        cout << "Cannot open input file.\n";
	return;
    }

    ofs <<  " digraph M { \n ";
    
    string str;
    while (std::getline(in, str)) 
    {
        char a[80],b[80],c[80];
	sscanf(str.c_str(),"%s\t%s\t%s",a,b,c);
        ofs << a << "->" << b << "[label=\"" << c << "\"]\n" ;
    }
    
    ofs << "}" ;
    in.close();
    ofs.close();
    
    
    
}

void GenFSM::process() {
    
    vector<System> *ptrSystems = &(parserObj.systems );
    vector<Agent> *ptrAgents = &(parserObj.agents);
    
    int i;
    
    //process systems 
    for(i =0; i< parserObj.systems.size(); i++ ){
        System *ptrSys = &(ptrSystems->at(i));
        writeSystemFiles(ptrSys);
        char fname[80];
        sprintf(fname, "%c.txt",ptrSys->name);
        createDot(fname,ptrSys->name);
    }
    
    //process agents 
    for(i =0; i< parserObj.agents.size(); i++ ){
        Agent *ptrAgent = &(ptrAgents->at(i));
        writeAgentFiles(ptrAgent);
        char fname[80];
        sprintf(fname, "%c.txt",ptrAgent->name);
        createDot(fname,ptrAgent->name);
    }
    
}