#ifndef SRC_COMPONENT_H
#define SRC_COMPONENT_H

#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

enum COMPT{
    X,Y,D,M,K,T,Z,N
};

enum TYPE{
    INT,REAL,BOOL,DINT,R_TRIG
};

class Component {
private:
    map<string,TYPE> x;
    map<string,TYPE> y;
    map<string,TYPE> m;
    map<string,TYPE> d;
    map<string,TYPE> t;
    map<string,TYPE> z;
    map<string,TYPE> k;

public:
   int add_compt(COMPT compt,TYPE type,string index);
   void output_var();
   void output_var_to_file(ofstream& );
};


#endif //SRC_COMPONENT_H