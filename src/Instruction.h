#ifndef SRC_INSTRUCTION_H
#define SRC_INSTRUCTION_H

#include <vector>
#include <string>
#include "Component.h"
using namespace std;

enum ISTR
{
    ADDP,
    ANB,
    AND,
    AND_L,
    AND_LE,
    AND_E,
    AND_G,
    AND_GE,
    ANDD_E,
    ANDD_GE,
    ANDP,
    ANI,
    LD,
    MPP,
    MPS,
    MRD,
    OUT,
    RST,
    SET,

    EQ,
    JMPCN,
    MUL,
    ST,
};
ISTR string_to_ISTR(string cmd){
    if(cmd == "ADDP"){
        return ADDP;
    }
    if(cmd == "ANB"){
        return ANB;
    }
    if(cmd == "AND"){
        return AND;
    }
    if(cmd == "AND_L"){
        return AND_L;
    }
    if(cmd == "AND_LE,"){
        return AND_LE,;
    }
    if(cmd == "AND_E"){
        return AND_E;
    }
    if(cmd == "AND_G"){
        return AND_G,;
    }
    if(cmd == "AND_GE"){
        return AND_GE;
    }
    if(cmd == "ANDD_E"){
        return ANDD_E;
    }
    if(cmd == "ANDD_GE"){
        return ANDD_GE;
    }
    if(cmd == "ANDP"){
        return ANDP;
    }
    if(cmd == "ANI"){
        return ANI;
    }
    if(cmd == "LD"){
        return ANDP;
    }
    if(cmd == "MPP"){
        return MPP;
    }
    if(cmd == "MPS"){
        return MPS;
    }
    if(cmd == "MRD"){
        return MRD;
    }
    if(cmd == "OUT"){
        return OUT;
    }
    if(cmd == "RST"){
        return RST;
    }
    if(cmd == "SET"){
        return SET;
    }
    if(cmd == "EQ"){
        return EQ;
    }
    if(cmd == "JMPCN"){
        return JMPCN;
    }
    if(cmd == "MUL"){
        return MUL;
    }
    if(cmd == "ST"){
        return ST;
    }
}
class compt
{
public:
    COMPT type;
    int index;
    compt(COMPT type, int index)
    {
        type = type;
        index = index;
    };
};

class Instruction
{
private:
    ISTR cmd;
    int lable;
    vector<compt> comp;
    int jmp_lable;

public:
    COMPT get_comp_i_type(int i);
    ISTR get_cmd();
    vector<compt> get_comp();
    int get_comp_num();
    Instruction();
    Instruction(ISTR cmd, int lable, int jmp_lable);
    Instruction(ISTR cmd, int lable, vector<compt> comp);
    Instruction(string cmd, vector<compt> comp);
    char get_comp_i_type_char(int i);
    int get_comp_i_index(int i);
};

int Instruction::get_comp_i_index(int i)
{
    return comp[i].index;
}

char Instruction::get_comp_i_type_char(int i)
{
    COMPT c = comp[i].type;
    char res = 'K';
    switch (c)
    {
    case X:
        res = 'X';
        break;
    case Y:
        res = 'Y';
        break;
    case D:
        res = 'D';
        break;
    case K:
        res = 'K';
        break;
    case T:
        res = 'T';
        break;
    case Z:
        res = 'Z';
        break;
    case M:
        res = 'M';
        break;
    default:
        cout<<"[ERROR] : wrong compt type"<<endl;
        break;
    }
    return res;
}
int Instruction::get_comp_num()
{
    return comp.size();
}
vector<compt> Instruction::get_comp()
{
    return comp;
}
Instruction::Instruction(string cmd,  vector<compt> comp)
{
    ISTR istr_tmp = string_to_ISTR(cmd);
    cmd = istr_tmp;
    lable = -1;
    comp = comp;
}

Instruction::Instruction(ISTR cmd, int lable, vector<compt> comp)
{
    cmd = cmd;
    lable = lable;
    comp = comp;
}
Instruction::Instruction(ISTR cmd, int lable, int jmp_lable)
{
    cmd = cmd;
    lable = lable;
    jmp_lable = jmp_lable;
}

Instruction::Instruction()
{
    lable = -1;
    jmp_lable = -1;
}

COMPT Instruction::get_comp_i_type(int index)
{
    return comp[index].type;
}

ISTR Instruction::get_cmd()
{
    return cmd;
}


#endif //SRC_INSTRUCTION_H


