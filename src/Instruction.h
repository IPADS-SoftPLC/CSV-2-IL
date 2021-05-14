#ifndef SRC_INSTRUCTION_H
#define SRC_INSTRUCTION_H

#include <vector>
using namespace std;

enum ISTR{
    ADDP,ANB,AND,AND_L,AND_LE,AND_E,AND_G,AND_GE,ANDD_E,ANDD_GE,ANDP,ANI,
    LD,ST,
};

enum COMP{
    X,Y,D,M,K,T,Z
};

struct component{
    COMP type;
    int index;
};

class Instruction {
public:
    ISTR cmd;
    int comp_num;
    vector<component> comp;

};

#endif //SRC_INSTRUCTION_H
