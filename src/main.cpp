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
    Component var;
    list<Instruction> old_instr;

    ifstream fin("../MAIN.csv"); //打开文件流操作

    string line;
    while (getline(fin, line))
    {
        istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
        vector<string> fields;   //声明一个字符串向量
        string field;

        while (getline(sin, field, '\t')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
        {
            fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
        }
        /*
         *  fields[2] : 指令
         *  fields[3] : 操作元件
         */

        cout << fields[2] << '\t' << fields[3] << endl;
    }

    // ifstream resFile;
    // resFile.open("IL.txt", ios::out | ios::in);

    list<Instruction>::iterator it;
    list<Instruction> new_instr;
    int lable = 0; // 先给jump用了 等下一行到了再加加
    bool lable_flag = 0;

    for (it = old_instr.begin(); it != old_instr.end(); it++)
    {
        ISTR cmd = (*it).get_cmd();
        vector<compt> comp;
        vector<compt> cout_comp;

        switch (cmd)
        {
        case LD:
            if (lable_flag)
            {
                cout << "lable" << lable << ":"
                     << "\tLD\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;
                new_instr.push_back(Instruction(cmd, lable, (*it).get_comp()));
                lable++;

                cout_comp = (*it).get_comp();
                lable_flag = false;
            }
            else
            {
                cout << "\tLD\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;
                new_instr.push_back(Instruction(cmd, -1, (*it).get_comp()));
            }

            comp.push_back(compt(K, 1));
            cout << "\tEQ\tK" << 1 << endl;
            cout << "\tJMPCN\tlable" << lable << endl;
            new_instr.push_back(Instruction(EQ, -1, comp));
            new_instr.push_back(Instruction(JMPCN, -1, lable));
            comp.clear();
            lable_flag = true;

            break;
        case SET:
            comp.push_back(compt(K, 1));
            if (lable_flag)
            {
                cout << "lable" << lable << ":"
                     << "\tLD\tK" << 1 << endl;
                new_instr.push_back(Instruction(LD, lable, comp));
                lable++;
            }
            else
            {
                cout << "\tLD\tK" << 1 << endl;
                new_instr.push_back(Instruction(LD, -1, comp));
            }
            cout << "\tST\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;
            new_instr.push_back(Instruction(ST, -1, (*it).get_comp()));
            comp.clear();

            break;

        case RST:
            comp.push_back(compt(K, 0));
            if (lable_flag)
            {
                new_instr.push_back(Instruction(LD, lable, comp));
                lable++;
            }
            else
            {
                new_instr.push_back(Instruction(LD, -1, comp));
            }
            new_instr.push_back(Instruction(ST, -1, (*it).get_comp()));
            comp.clear();

            break;

        case AND:
            if (lable_flag)
            {
                new_instr.push_back(Instruction(LD, lable, (*it).get_comp()));
                lable++;
            }
            else
            {
                new_instr.push_back(Instruction(LD, -1, (*it).get_comp()));
            }

            comp.push_back(compt(K, 1));
            new_instr.push_back(Instruction(EQ, -1, comp));
            new_instr.push_back(Instruction(JMPCN, -1, lable));
            comp.clear();
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