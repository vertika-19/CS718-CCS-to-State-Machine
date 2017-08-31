/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "parser.h"


using namespace std;

Parser parserObj;
extern RcvInput rcvInputObj;

Parser::Parser() {
    agents.clear();
    systems.clear();
    mapAgentNameToObj.clear();
}

Parser::~Parser() {

}

void Parser::addAgents(string s) {
    size_t index = 0;
    int count = 1;
    string temp;

    Agent agentObj;
    agentObj.name = s[0];

    cout << "In agents " << s[0] << endl;
    s = s.substr(2);

    while (1) {
        //cout << s << " in loop " << endl;
        index = s.find_first_of('+');
        if (index != string::npos) {
            temp = s.substr(0, index);
            agentObj.expr.push_back(temp);
            cout << "pushed " << temp << endl;

            int countChar = 0;
            for (int i = 0; i < temp.length(); i++) {
                if (s[i] >= 97 && s[i] <= 122) {
                    countChar++;
                }
            }

            if (temp[temp.length() - 1] == '0') {
                count += countChar;
            } else {
                count += countChar - 1;
            }
            //cout << count << endl;
        } else {
            temp = s.substr(0);
            agentObj.expr.push_back(temp);
            cout << "pushed " << temp << endl;

            int countChar = 0;
            for (int i = 0; i < temp.length() - 1; i++) {
                if (s[i] >= 97 && s[i] <= 122) {
                    countChar++;
                }
            }

            if (temp[temp.length() - 1] == '0') {
                count += countChar;
            } else {
                count += countChar - 1;
            }
            // cout << count << endl;

            break;
        }
        s = s.substr(index + 1);
    }
    agentObj.noOfStates = count;
    cout << "No of states for this agent " << agentObj.noOfStates << endl;

    agentObj.table = new string*[agentObj.noOfStates];

    for (int i = 0; i < agentObj.noOfStates; i++) {
        agentObj.table[i] = new string[agentObj.noOfStates];
        for (int j = 0; j < agentObj.noOfStates; j++) {
            agentObj.table[i][j].clear();
        }
    }

    if( mapAgentNameToObj.find(agentObj.name) != mapAgentNameToObj.end()) {
        cout << " FAIL : Agent with same name already exists " << endl;
        return;

    }
    mapAgentNameToObj.insert(pair<char, Agent>(agentObj.name, agentObj));
    agents.push_back(agentObj);
}

void Parser::addSystem(string s) {

    System sysObj;
    size_t i1 = 0;
    size_t i2 = 0;

    i1 = s.find_first_of('(');
    i2 = s.find_first_of(')');

    sysObj.name = s[0];
    sysObj.expr = s.substr(i1 + 1, i2 - i1 - 1);
    //cout << "System expression " << sysObj.expr << endl;

    i1 = s.find_first_of('{');
    i2 = s.find_first_of('}');
    sysObj.restriction = s.substr(i1 + 1, i2 - i1 - 1);
    //cout << "System restriction " << sysObj.restriction << endl;
    sysObj.noOfStates = 1;
    
    for(int i= 0;i< (sysObj.expr).length();i++) {
        Agent ag = parserObj.mapAgentNameToObj[(sysObj.expr)[i]];
        sysObj.agentAndNoOfStates.push_back( pair<char,int>(ag.name,ag.noOfStates ) ); 
        sysObj.noOfStates *= ag.noOfStates;
    }
    
    
    sysObj.table = new string*[sysObj.noOfStates];

    for (int i = 0; i < sysObj.noOfStates; i++) {
        sysObj.table[i] = new string[sysObj.noOfStates];
        for (int j = 0; j < sysObj.noOfStates; j++) {
            sysObj.table[i][j].clear();
        }
    }
    systems.push_back(sysObj);
}

void Parser::process() {

    for (int i = 0; i < rcvInputObj.agentExp.size(); i++) {

        string s = rcvInputObj.agentExp[i];
        s.erase(remove(s.begin(), s.end(), '.'), s.end());
        s.erase(remove(s.begin(), s.end(), ','), s.end());
        s.erase(remove(s.begin(), s.end(), '|'), s.end());
            
        cout << "In process " << s << endl; 
        
        if (s.find('{') != string::npos) {
            //cout << "System " << s <<  endl;
            addSystem(s);
        } else {
            //cout << "Agent" << s << endl;
            addAgents(s);
        }
    }



}
