#include "build_agent_table.h"

BuildAgentTable agentTableObj;
extern Parser parserObj;

BuildAgentTable::BuildAgentTable() {
    ptrVecAgents = NULL;
    ptrAgentExprs = NULL;
}

BuildAgentTable::~BuildAgentTable() {

}

void BuildAgentTable::buildTable() {


        int start;
        int len;
        int curr;
           Agent ag;
        
    ptrVecAgents = &(parserObj.agents);

    //iterate over all agents one by one
    for (int k = 0; k < ptrVecAgents->size(); k++) {

        //particular agent
        ag = ptrVecAgents->at(k);
        start = 0;

        
        
        //get all expressions for an agent
        ptrAgentExprs = &(ag.expr);


        curr = start;

        //iterate over all expressions for an agent
        for (int index = 0; index < ptrAgentExprs->size(); index++) {

            //agent expression 
            string s = ptrAgentExprs->at(index);

            len = s.length();

            int stepSize;
            int i = 0;

            while (i < len - 1) {
                
                // variable to be stored corresponding to state transition
                string alpha = "";

                // for complemented variable
                if ((i != len - 2)&&(s[i + 1] == '\'')) {
                    alpha += s[i]; // adding variable name
                    alpha += s[i + 1]; // adding complement sign
                    stepSize = 2;
                } else { // for un-complemented variable
                    alpha = s[i]; // adding variable name
                    stepSize = 1;
                }

                //A0->Ai
                
                if (((i == len - 3)&&(stepSize == 2)) || ((i == len - 2)&&(stepSize == 1))) {
                    
                    if (s[len - 1] == '0')
                        ag.table[curr][curr + 1] = alpha;
                    else {
                        ag.table[curr][start] = alpha;
                        curr--;
                    }

                }  else if (i == 0) {
                    
                    ag.table[start][curr + 1] = alpha;
                    

                }
                else {
                    ag.table[curr][curr + 1] = alpha;

                }
                curr++;
                i += stepSize;
            }
        }
        
        ptrAgentExprs = NULL;

        //print table for an agent
        cout << "Agent name : " << ag.name << " with " << ag.noOfStates << " states " << endl;
        for (int i = 0; i < ag.noOfStates; i++) {
            for (int j = 0; j < ag.noOfStates; j++) {
                cout << ag.table[i][j] << " ";
            }
            cout << endl;
        }
    }


}
