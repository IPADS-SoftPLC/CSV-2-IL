#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include "Instruction.h"

using namespace std;

void generate_new_instr(list<Instruction> &instr);

int main()
{
    list<Instruction> old_instr;
    // ifstream resFile;
    // resFile.open("IL.txt", ios::out | ios::in);

    list<Instruction>::iterator it;
    // list<Instruction> new_instr;
    int lable = 0; // 先给jump用了 等下一行到了再加加
    bool lable_flag = 0;

    for (it = old_instr.begin(); it != old_instr.end(); it++)
    {
        ISTR cmd = (*it).get_cmd();
        vector<compt> comp;

        switch (cmd)
        {
        case LD:
            if (lable_flag)
            {
                cout << "lable" << lable << ":"
                     << "\tLD\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;
                lable++;
                lable_flag = false;
            }
            else
            {
                cout << "\tLD\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;
            }

            cout << "\tEQ\tK" << 1 << endl;
            cout << "\tJMPCN\tlable" << lable << endl;
            lable_flag = true;

            break;
        case SET:
            if (lable_flag)
            {
                cout << "lable" << lable << ":"
                     << "\tLD\tK" << 1 << endl;
                lable++;
                lable_flag = false;
            }
            else
            {
                cout << "\tLD\tK" << 1 << endl;
            }
            cout << "\tST\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;

            break;

        case RST:

            if (lable_flag)
            {
                cout << "lable" << lable << ":"
                     << "\tLD\tK" << 0 << endl;
                lable++;
                lable_flag = false;
            }
            else
            {
                cout << "\tLD\tK" << 0 << endl;
            }
            cout << "\tST\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;

            break;

        case AND:
            if (lable_flag)
            {
                cout << "lable" << lable << ":"
                     << "\tLD\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;
                lable++;
                lable_flag = false;
            }
            else
            {
                cout << "\tLD\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;
            }

            cout << "\tEQ\tK" << 1 << endl;
            cout << "\tJMPCN\tlable" << lable << endl;

            lable_flag = true;
            break;

        case OUT:

            break;
        default:
            break;
        }
    }

    return 0;
}

void generate_new_instr(list<Instruction> &instr)
{
    list<Instruction>::iterator it;
    int lable = 0; // 先给jump用了 等下一行到了再加加
    bool lable_flag = 0;

    for (it = instr.begin(); it != instr.end(); it++)
    {
    }

    return;
}