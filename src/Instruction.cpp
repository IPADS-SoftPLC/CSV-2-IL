#include "Instruction.h"

string Instruction::get_comp_i_index(int i)
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
        // cout<<"[ERROR] : wrong compt type"<<endl;
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
