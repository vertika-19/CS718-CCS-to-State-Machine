/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "build_sys_table.h"
#include "build_agent_table.h"

using namespace std;
extern Parser parserObj;
BuildSystemTable buildSystemTableObj;

BuildSystemTable::BuildSystemTable() {

}

BuildSystemTable::~BuildSystemTable() {

}

int* BuildSystemTable::calcIndices(int agNo, int stNo, int noOfStates) {
    
    int span, start, curr, k, gap, i, j;

    int nextall = nextSum[agNo - 1];
    int prevall = prevSum[agNo - 1];
    int *arr = (int *)malloc( (nextall * prevall)*sizeof(int));
    span = nextall;
    start = (stNo - 1) * nextall + 1;
    gap = (noOfStates - 1) * nextall;
    curr = start;
    k = 0; 
    for (i = 1; i <= (prevall); i++) // number of steps = (prevall*nextall)/nextall
    {
        for (j = curr; j <= curr + span - 1; j++) 
        {
            arr[k++] = j;
        }
        curr = curr + span + gap;
    }
    return arr;
}

void BuildSystemTable::calNextSum(System sys) {
    
    int i,temp=1;
    nextSum.clear();
    
    nextSum.push_back(1);
    for(i = sys.agentAndNoOfStates.size()-2; i >=0;i--) {
        pair<char,int> p = sys.agentAndNoOfStates[i+1];
        temp = temp* (p.second);
        nextSum.push_back(temp);
    }
    reverse(nextSum.begin(),nextSum.end());
}

void BuildSystemTable::calPrevSum(System sys) {
    
    int i,temp=1;
    prevSum.clear();
    
    prevSum.push_back(1);
    for(i = 1; i < sys.agentAndNoOfStates.size();i++) {
        pair<char,int> p = sys.agentAndNoOfStates[i-1];
        temp = temp* (p.second);
        prevSum.push_back(temp);
    }
}

void BuildSystemTable::buildTable() {

    int i,j,k1,k2,r,c;
    vector< System > *sys = &(parserObj.systems);
    for(i=0;i<parserObj.systems.size();i++)
    {
        System s = sys->at(i);
        calNextSum(s);
        calPrevSum(s);
        string str = s.expr;
        for(j=0;j<str.length();j++)
        {
            
            Agent ag = parserObj.mapAgentNameToObj[str[j]];
            for(k1=0;k1<ag.noOfStates;k1++)
            {
                for(k2=0;k2<ag.noOfStates;k2++)
                {
                    //cout <<k1<<" "<<k2<<endl;
                    if(!(ag.table[k1][k2]).empty())
                    {
                        int *l1,*l2;
                        l1 = calcIndices(j+1,k1+1,ag.noOfStates);
                        l2 = calcIndices(j+1,k2+1,ag.noOfStates);
                        
                        for(r=0;r<nextSum[j]*prevSum[j];r++)
                        {
                            for(c=0;c<nextSum[j]*prevSum[j];c++)
                            {
                                if((s.table[l1[r]-1][l2[c]-1]).empty())
                                    s.table[l1[r]-1][l2[c]-1]= ag.table[k1][k2];
                                else if(s.table[l1[r]-1][l2[c]-1]=="N")
                                {
                                    //do nothing
                                }
                                else
                                {
                                    string sysstr = s.table[l1[r]-1][l2[c]-1];
                                    string agstr = ag.table[k1][k2];
                                    // row no and col no same - diagonal 
                                 /**   if( l1[r]-1 == l2[c]-1 ) {
                                        s.table[l1[r]-1][l2[c]-1] += ",";
                                        s.table[l1[r]-1][l2[c]-1] += ag.table[k1][k2];
                                        if( (ag.table[k1][k2]).length() == 1 ) {
                                            string str = ag.table[k1][k2]+ "\'";
                                            int found = (s.table[l1[r]-1][l2[c]-1]).find(str);
                                            if( found != string::npos) {
                                                s.table[l1[r]-1][l2[c]-1] += ",";
                                                s.table[l1[r]-1][l2[c]-1] += "tau";
                                            }
                                        } else {
                                            string str = ag.table[k1][k2];
                                            int found = (s.table[l1[r]-1][l2[c]-1]).find(str[0]);
                                            if( found != string::npos) {
                                                s.table[l1[r]-1][l2[c]-1] += ",";
                                                s.table[l1[r]-1][l2[c]-1] += "tau";
                                            }
                                        }
                                    } **/
                                    if((sysstr == (agstr+"\'"))||(agstr == (sysstr+"\'")))
                                    {
                                        //complemented
                                        s.table[l1[r]-1][l2[c]-1]="tau";
                                    }
                                    else
                                    {
                                        //different
                                        s.table[l1[r]-1][l2[c]-1]="N";
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        for( r = 0; r < s.noOfStates ; r++ ) { 
            for(  c = 0 ;c < s.noOfStates;c++ ) {
                cout << s.table[r][c] << "\t";
            }
            cout << endl;
        }
        
    }
    
    
}