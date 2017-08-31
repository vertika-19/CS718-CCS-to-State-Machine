/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   agent.h
 * Author: vertika
 *
 * Created on 21 April, 2017, 10:24 PM
 */

#ifndef AGENT_H
#define AGENT_H

using namespace std;


#include <string>
#include <vector>
    
class Agent {
    public :
        char name;
        int noOfStates;
        vector< string > expr;
	string** table;
        
    public :
        Agent();
        ~Agent();
    vector<string> GetExpr() const {
        return expr;
    }

    void SetExpr(vector<string> expr) {
        this->expr = expr;
    }

    char GetName() const {
        return name;
    }

    void SetName(char name) {
        this->name = name;
    }

    int GetNoOfStates() const {
        return noOfStates;
    }

    void SetNoOfStates(int noOfStates) {
        this->noOfStates = noOfStates;
    }

    
};

#endif /* AGENT_H */

