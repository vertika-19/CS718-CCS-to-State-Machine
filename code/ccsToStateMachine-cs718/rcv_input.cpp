

#include "rcv_input.h"

using namespace std;

RcvInput rcvInputObj;

RcvInput::RcvInput() {
    
    
}

RcvInput::~RcvInput() {
    
}

void RcvInput::readFile(char* fname)
{
    ifstream in(fname);
    if(!in) 
    {
        cout << "Cannot open input file.\n";
	return;
    }

    string str;
    while (std::getline(in, str)) 
    {
	string::iterator end_pos = remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
	agentExp.push_back(str);
    }
   in.close();
}