#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include "Instruction.h"
#include "Component.h"

using namespace std;
list<Instruction> old_instr;
Component var;
vector<compt> comp;
void output_list(list<Instruction> old_instr)
{
    list<Instruction>::iterator iter;
    cout << "start" << endl;
    for (iter = old_instr.begin(); iter != old_instr.end(); iter++)
    {
        ISTR cmd = (*iter).get_cmd();
        vector<compt> comp = (*iter).get_comp();

        cout << cmd << " ";

        for (int i = 0; i < comp.size(); i++)
            cout << (*iter).get_comp_i_type_char(i) << (*iter).get_comp_i_index(i) << " ";
        cout << endl;
    }
}
string remove_nut(string field)
{
    string res = "";
    for (int i = 0; i < field.size(); i++)
        if (field[i] != 0)
            res = res + field[i];
    return res;
}
COMPT char_to_COMPT(char target)
{
    switch (target)
    {
    case 'X':
        return X;
    case 'Y':
        return Y;
    case 'D':
        return D;
    case 'M':
        return M;
    case 'K':
        return K;
    case 'T':
        return T;
    case 'Z':
        return Z;
    default:
        return N;
    }
}

void csv_to_il(ofstream &outfile);
void add_var(Component &var, Instruction &instr);
bool is_cmd_de(ISTR cmd);
TYPE get_type(COMPT comp);

void creat_intr(string target, string one_compt, string &instr_name)
{
    if (target != "")
    {
        if (comp.size() != 0)
        {
            Instruction il = Instruction(instr_name, comp);
            ISTR cmd = il.get_cmd();
            cout << cmd << endl;
            old_instr.push_back(il);

            /*  更新变量  */
            add_var(var, il);
            if (il.get_cmd() == ANDP || il.get_cmd() == LDP) /* 还不全 */
            {
                var.add_compt(il.get_comp_i_type(0), R_TRIG, il.get_comp_i_index(0) + "_tmp");
            }
            /*************/
            comp.clear();
        }
        instr_name = target;
        if (one_compt == "")
        {
            return;
        }
        COMPT compt_type = char_to_COMPT(one_compt[0]);
        string compt_index = "";
        for (int i = 1; i < one_compt.length(); i++)
            compt_index = compt_index + one_compt[i];
        comp.push_back(compt(compt_type, compt_index));
    }
    else
    {
        if (one_compt == "")
            return;
        COMPT compt_type = char_to_COMPT(one_compt[0]);
        string compt_index = "";
        for (int i = 1; i < one_compt.length(); i++)
            compt_index = compt_index + one_compt[i];
        comp.push_back(compt(compt_type, compt_index));
    }
}
int main()
{

    ifstream fin("../test/pump-line1.csv"); //打开文件流操作

    string line;
    int num_MPS = 0;
    int num_MPS_inst = 0;
    vector<compt> comp;
    string instr_name;
    vector<vector<vector<string>>> content_MPS(10);
    for (int n = 0; n < 10; n++)
    {
        content_MPS[n].resize(10);
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            content_MPS[i][j].resize(10);
        } //之后才能对三维数组设定大小，否则内存出错
    }

    while (getline(fin, line))
    {
        istringstream sin(line);
        vector<string> fields; //声明一个字符串向量
        string field;
        while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
        {
            field = remove_nut(field);

            fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
        }
        if (true)
        {

            string target = fields[2];
            if (target == "MPS")
            {

                num_MPS++;

                for (int j = 0; j < num_MPS; j++)
                {

                    for (int i = 0; i < content_MPS[j].size(); i++)
                    {
                        creat_intr(content_MPS[j][i][2], content_MPS[j][i][3], instr_name);
                        cout << content_MPS[j][i][2] << ' ' << content_MPS[j][i][3] << endl;
                    }
                }
                num_MPS_inst = 0;
            }
            else if (target == "MPP")
            {
                for (int j = 0; j < num_MPS; j++)
                {
                    for (int i = 0; i < content_MPS[j].size(); i++)
                    {
                        creat_intr(content_MPS[j][i][2], content_MPS[j][i][3], instr_name);
                        cout << content_MPS[j][i][2] << ' ' << content_MPS[j][i][3] << endl;
                    }
                }

                num_MPS--;
            }
            else if (target == "MRD")
            {
                for (int j = 0; j < num_MPS; j++)
                {
                    for (int i = 0; i < content_MPS[j].size(); i++)
                    {
                        creat_intr(content_MPS[j][i][2], content_MPS[j][i][3], instr_name);
                        cout << content_MPS[j][i][2] << ' ' << content_MPS[j][i][3] << endl;
                    }
                }
            }
            else if (target == "LD")
            {
                num_MPS_inst = 0;
                content_MPS[num_MPS].clear();
                content_MPS[num_MPS].push_back(fields);
                num_MPS_inst++;

                creat_intr(fields[2], fields[3], instr_name);

                cout << fields[2] << " " << fields[3] << endl;
            }
            else
            {
                content_MPS[num_MPS].push_back(fields);
                num_MPS_inst++;
                creat_intr(fields[2], fields[3], instr_name);
                cout << fields[2] << " " << fields[3] << endl;
            }
        }
    }

    ofstream outfile;
    outfile.open("result.il");
    outfile << "PROGRAM ABC" << endl;
    // output_list(old_instr);
    // cout << "[RESULT]:new instruction list" << endl;
    var.add_compt(K,BOOL,"0");
    var.add_compt(K,BOOL,"1");
    // var.add_compt(K,BOOL,"1_BOOL");
    var.output_var_to_file(outfile);
    csv_to_il(outfile);
    outfile<<"END_PROGRAM"<<endl;
    outfile.close();
    return 0;
}

void csv_to_il(ofstream &outfile)
{
    
    int lable = 0; // 先给jump用了 等下一句要用lable的指令用完了再加加
    bool lable_flag = 0;
    bool new_line = 0; // 如果下一句指令是新行 则置为true  OUT等特定指令的下一句就是new_line
    list<Instruction>::iterator it;
    string tmp;
    for (it = old_instr.begin(); it != old_instr.end(); it++)
    {
        ISTR cmd = (*it).get_cmd();
        // add_var(var, *it);
        switch (cmd)
        {
        case LD:
            if (lable_flag && new_line)
            {
                outfile << "lable" << lable << ":"
                        << "\tLD\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;
                lable++;
                lable_flag = false;
                new_line = false;
            }
            else
            {
                outfile << "\t\tLD\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;
            }

            outfile << "\t\tEQ\tK" << 1 << endl;

            outfile << "\t\tJMPCN\tlable" << lable << endl;
            lable_flag = true;

            break;
        case SET:
            // if (lable_flag && new_line)
            // {
            //     outfile << "lable" << lable << ":"
            //             << "\tLD\tK" << 1 << endl;
            //     lable++;
            //     lable_flag = false;
            // }
            // else
            // {
                outfile << "\t\tLD\tK" << 1 << endl;
            // }
            outfile << "\t\tST\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;

            new_line = true;
            break;

        case RST:

            // if (lable_flag && new_line)
            // {
            //     outfile << "lable" << lable << ":"
            //             << "\tLD\tK" << 0 << endl;
            //     lable++;
            //     lable_flag = false;
            // }
            // else
            // {
                outfile << "\t\tLD\tK" << 0 << endl;
            // }
            outfile << "\t\tST\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;

            new_line = true;
            break;

        case AND:

            outfile << "\t\tLD\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;

            outfile << "\t\tEQ\tK" << 1 << endl;
            outfile << "\t\tJMPCN\tlable" << lable << endl;

            lable_flag = true;
            break;

        case ANI:
            outfile << "\t\tLD\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;
            outfile << "\t\tEQ\tK" << 0 << endl;
            outfile << "\t\tJMPCN\tlable" << lable << endl;
            lable_flag = true;

            break;

        case ANDP:
            /* 相当于 AND lDP */
            tmp = "M" + (*it).get_comp_i_index(0) + "_tmp";
            outfile << "\t\tLD\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;
            // var.add_compt( (*it).get_comp_i_type(0),R_TRIG,(*it).get_comp_i_index(0)+"_tmp");
            outfile << "\t\tST\t" << tmp << ".CLK" << endl;
            outfile << "\t\tCAL\t" << tmp << endl;
            outfile << "\t\tLD\t" << tmp << ".Q" << endl;
            outfile << "\t\tEQ\tK1"  << endl;
            outfile << "\t\tJMPCN\tlable" << lable << endl;
            lable_flag = true;

            break;

        case OUT:
            /* 
             * 前面一定有类似LD的指令， 所以一定lable_flag=true 
             * 现在lable的值（LD为0要跳到的地方）要用于为0时 OUt 要执行的地方
             * lable+1 要用于下一行 也就是下一句指令 ： 所以要把 lable_flag = true , new_line = true 
             */
            if (!lable_flag)
                outfile << "[ERROR]: wrong lable_flag value" << endl;

            if (it->get_comp_i_type(0) == T)
            {
                /* 对T操作 两个操作数*/
                outfile << "\t\tLD\t" << (*it).get_comp_i_type_char(1) << (*it).get_comp_i_index(1) << endl;
                outfile << "\t\tST\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;
                new_line = true;
            }
            else
            {
                /* 一个操作数的OUT */
                outfile << "\t\tLD\tK" << 1 << endl;
                outfile << "\t\tST\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;
                outfile << "\t\tJMPCN\tlable" << lable + 1 << endl;
                outfile << "lable" << lable << ":\tLD\tK" << 0 << endl;
                outfile << "\tST\t" << (*it).get_comp_i_type_char(0) << (*it).get_comp_i_index(0) << endl;

                lable++;
                new_line = true;
            }

            break;
        default:
            break;
        }
    }
    outfile << "lable" << lable << ":\tLD\tK0" << endl;
}

void add_var(Component &var, Instruction &instr)
{
    ISTR cmd = instr.get_cmd();
    int comp_num = instr.get_comp_num();
    bool is_real = is_cmd_de(cmd);
    if (cmd == FLT)
    {
        var.add_compt(instr.get_comp_i_type(0), INT, instr.get_comp_i_index(0));
        var.add_compt(instr.get_comp_i_type(1), REAL, instr.get_comp_i_index(1));
        return;
    }
    if (cmd == DFLT)
    {
        var.add_compt(instr.get_comp_i_type(0), DINT, instr.get_comp_i_index(0));
        var.add_compt(instr.get_comp_i_type(1), REAL, instr.get_comp_i_index(1));
        return;
    }
    for (int i = 0; i < comp_num; i++)
    {
        if (is_real)
        {
            var.add_compt(instr.get_comp_i_type(i), REAL, instr.get_comp_i_index(i));
        }
        else
        {
            var.add_compt(instr.get_comp_i_type(i), get_type(instr.get_comp_i_type(i)), instr.get_comp_i_index(i));
        }
    }
}

bool is_cmd_de(ISTR cmd)
{
    if (cmd >= DECP && cmd <= DEMUL)
        return true;
    else
        return false;
}

TYPE get_type(COMPT comp)
{
    switch (comp)
    {
    case X:
    case Y:
    case M:
        return BOOL;
        break;

    default:
        return INT;
        break;
    }
}
