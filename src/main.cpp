#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include "Instruction.h"

using namespace std;



string Trim(string &str) {
    //str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
    str.erase(0, str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
    return str;
}

int main() {
    vector<bool> x;
    vector<bool> y;
    vector<bool> m;
    vector<float> d;


    list<Instruction> old_instr;

    ifstream fin("../MAIN.csv"); //打开文件流操作

    string line;
    while (getline(fin, line)) {
        istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
        vector<string> fields; //声明一个字符串向量
        string field;

        while (getline(sin, field, '\t')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
        {
            fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
        }
        /*
         *  fields[2] : 指令
         *  fields[3] : 操作元件
         */

        cout<<fields[2]<<'\t'<<fields[3]<<endl;



    }
    return 0;

}
