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
vector<compt> comp;
void output_list(list<Instruction> old_instr){
   list<Instruction>::iterator iter;
   cout<<"遍历开始"<<endl;
    for(iter = old_instr.begin(); iter != old_instr.end() ;iter++)
    {
        ISTR cmd = (*iter).get_cmd();
        vector<compt> comp = (*iter).get_comp();
      
        cout<<cmd<<" "<<endl;
      
        for(int i = 0; i<comp.size();i++)
            cout<<iter->get_comp_i_type_char(i)<<iter->get_comp_i_index(i)<<" ";
        cout<<endl;

    }
}
string remove_nut(string field){
    string res = "";
    for(int i=0;i<field.size();i++)
       if(field[i] != 0)
            res = res + field[i];
    return res;
}


COMPT char_to_COMPT(char target){
    switch(target){
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
    }
}
//Instruction(ISTR cmd, vector<compt> comp);
//comp.push_back(compt(K, 1));
void creat_intr(string target,string one_compt,string& instr_name){
    // cout<<target<<" "<<one_compt<<endl;
    if(target != ""){
        if(comp.size() != 0){
            // cout<<instr_name<<" jjj"<<endl;
            // cout<<"uahcuey"<<endl;
            Instruction il= Instruction(instr_name, comp);
            ISTR cmd = il.get_cmd();
            cout<<cmd<<endl;
            old_instr.push_back(il);

            comp.clear();
        }
        instr_name = target;
        if(one_compt == ""){
            // cout<<"afafe"<<endl;
            return;
        }
        // cout<<one_compt[0]<<" kkk"<<endl;
        COMPT compt_type = char_to_COMPT(one_compt[0]);
        // cout<<one_compt[0]<<" k1k"<<endl;
        string compt_index = "";
        for(int i = 1; i<one_compt.length();i++)
            compt_index = compt_index + one_compt[i];
        // cout<<compt_type<<" "<<compt_index<<endl;
        comp.push_back(compt(compt_type,compt_index));
    }
    else{
        if(one_compt == "")
            return;
        COMPT compt_type = char_to_COMPT(one_compt[0]);
        //  cout<<one_compt[0]<<" kkk"<<endl;
        string compt_index = "";
        for(int i = 1; i<one_compt.length();i++)
            compt_index = compt_index + one_compt[i];
        // cout<<compt_type<<" "<<compt_index<<endl;
        comp.push_back(compt(compt_type,compt_index));
    }

}
int main() {
   
    ifstream fin("../test.csv"); //打开文件流操作

    string line;
    int num_MPS = 0;
    int num_MPS_inst =0;
    vector<compt> comp;
    string instr_name;
    vector<vector< vector<string> > > content_MPS(10);
    for (int n = 0; n < 10; n++)
    {
        content_MPS[n].resize(10);
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            content_MPS[i][j].resize(10);
        }//之后才能对三维数组设定大小，否则内存出错
    }
   
    while (getline(fin, line)) {
        istringstream sin(line); 
        vector<string> fields; //声明一个字符串向量
        string field;
        while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
        {
            field = remove_nut(field);
           
            fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
        }
        if(true){
            
            string target = fields[2];
            if(target == "MPS"){
               
                num_MPS++;
               
                for(int j =0 ;j < num_MPS ; j++){
                  
                    for(int i = 0 ;i<content_MPS[j].size();i++){
                        creat_intr(content_MPS[j][i][2],content_MPS[j][i][3],instr_name);
                         cout<<content_MPS[j][i][2]<<' '<<content_MPS[j][i][3]<<endl;
                    }
                }
                num_MPS_inst =0;

            }
            else if(target == "MPP"){
                for(int j =0 ;j < num_MPS ; j++){
                    for(int i = 0 ;i<content_MPS[j].size();i++){
                        creat_intr(content_MPS[j][i][2],content_MPS[j][i][3],instr_name);
                         cout<<content_MPS[j][i][2]<<' '<<content_MPS[j][i][3]<<endl;
                    }
                }
                
                num_MPS--;
            }
            else if(target == "MRD"){
                for(int j =0 ;j < num_MPS ; j++){
                    for(int i = 0 ;i<content_MPS[j].size();i++){
                        creat_intr(content_MPS[j][i][2],content_MPS[j][i][3],instr_name);
                         cout<<content_MPS[j][i][2]<<' '<<content_MPS[j][i][3]<<endl;
                    }
                }
            }
            else if(target == "LD"){
                num_MPS_inst = 0;
                content_MPS[num_MPS].clear();
                content_MPS[num_MPS].push_back(fields);
                num_MPS_inst ++ ;
                
                creat_intr(fields[2],fields[3],instr_name);

                cout<<fields[2]<<" "<<fields[3]<<endl;
            }
            else {
                content_MPS[num_MPS].push_back(fields);
                num_MPS_inst ++ ;
                creat_intr(fields[2],fields[3],instr_name);
                cout<<fields[2]<<" "<<fields[3]<<endl;
            }

        }
    }
    output_list(old_instr);
    return 0;

}
