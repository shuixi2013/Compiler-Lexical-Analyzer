#include "TransitionTable.h"


TransitionTable::TransitionTable( vector < vector <int> > MDFA ,
                                  unordered_map <char,int> input,
                                  vector <bool> finalState ,
                                  vector <string> tokenType )
{
    //ctor
    this->MDFA = MDFA;
    this->input_map = input;
    this->finalState = finalState;
    this->tokenType = tokenType;
}
vector < vector <int> > TransitionTable::Get_MDFA ()
{
    return MDFA;
}

int TransitionTable::Get_Input (char input)
{
    unordered_map<char,int>::const_iterator it =input_map.find(input);

    if (it!=input_map.end())
    {
        return it->second;
    }
    return -1;
}

bool TransitionTable::is_final (int state )
{
    if (state < finalState.size())
        return finalState[state];
    return false;
}

string TransitionTable::type (int state )
{
    if (state < tokenType.size())
        return tokenType[state];
    return "";
}

TransitionTable::~TransitionTable()
{
    //dtor
}
