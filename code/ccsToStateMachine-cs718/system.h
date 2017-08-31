/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   system.h
 * Author: vertika
 *
 * Created on 21 April, 2017, 10:25 PM
 */

#ifndef SYSTEM_H
#define SYSTEM_H

using namespace std;


#include <string>
#include <vector>
    
class System {
    
    public :
        char name;
        int noOfStates;
        vector< pair<char ,int> > agentAndNoOfStates;
        string expr;
        string restriction;
        string** table;
        
    public :
        System();
        ~System();
    string GetExpr() const {
        return expr;
    }

    void SetExpr(string expr) {
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

    string GetRestriction() const {
        return restriction;
    }

    void SetRestriction(string restriction) {
        this->restriction = restriction;
    }

    
};

#endif /* SYSTEM_H */

