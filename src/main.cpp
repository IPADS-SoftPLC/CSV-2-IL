#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include "Instruction.h"

using namespace std;

string remove_nut(string field){
    string res = "";
    for(int i=0;i<field.size();i++)
       if(field[i] != 0)
            res = res + field[i];
    return res;
}



int main() {
    vector<bool> x;
    vector<bool> y;
    vector<bool> m;
    vector<float> d;


    list<Instruction> old_instr;

    ifstream fin("../test.csv"); //打开文件流操作

    string line;
    int num_MPS = 0;
    int num_MPS_inst =0;
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
                        cout<<content_MPS[j][i][2]<<' '<<content_MPS[j][i][3]<<endl;
                    }
                }
                
                num_MPS_inst =0;

            }
            else if(target == "MPP"){
                for(int j =0 ;j < num_MPS ; j++){
                    for(int i = 0 ;i<content_MPS[j].size();i++){
                        cout<<content_MPS[j][i][2]<<' '<<content_MPS[j][i][3]<<endl;
                    }
                }
                
                num_MPS--;
            }
            else if(target == "MRD"){
                for(int j =0 ;j < num_MPS ; j++){
                    for(int i = 0 ;i<content_MPS[j].size();i++){
                        cout<<content_MPS[j][i][2]<<' '<<content_MPS[j][i][3]<<endl;
                    }
                }
                

            }
            else if(target == "LD"){
               
                num_MPS_inst = 0;
                content_MPS[num_MPS].clear();
                content_MPS[num_MPS].push_back(fields);
                
                num_MPS_inst ++ ;
                cout<<fields[2]<<" "<<fields[3]<<endl;
            }
            else {
                
                content_MPS[num_MPS].push_back(fields);
                
                num_MPS_inst ++ ;
                cout<<fields[2]<<" "<<fields[3]<<endl;
            }

        }
        else
            cout<<fields[2]<<" "<<fields[3]<<endl;
        /*
         *  fields[2] : 指令
         *  fields[3] : 操作元件
         */
        
    }
    return 0;

}
