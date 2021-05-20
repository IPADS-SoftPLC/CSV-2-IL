#ifndef SRC_INSTRUCTION_H
#define SRC_INSTRUCTION_H

#include <vector>
#include <string>
#include "Component.h"
#include <iostream>
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

    /* 浮点操作 不允许分开*/
    DECP,
    DEDIV,
    DEMOV,
    DEMUL,
    /* 浮点操作 不允许分开*/
    DFLT,
    FLT,
    LD,
    LDP,
    MEF,
    MEP,
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

    NONE
};

class compt
{
public:
    COMPT type;
    string index;
    compt(COMPT type, string index)
    {
        this->type = type;
        this->index = index;
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
    string get_comp_i_index(int i);
};

#endif //SRC_INSTRUCTION_H
