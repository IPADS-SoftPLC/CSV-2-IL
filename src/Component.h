#ifndef SRC_COMPONENT_H
#define SRC_COMPONENT_H

#include <vector>
#include <map>
#include <string>
using namespace std;

enum COMPT{
    X,Y,D,M,K,T,Z
};

enum TYPE{
    INT,REAL,BOOL,
};

class Component {
private:
    map<string,TYPE> x;
    map<string,TYPE> y;
    map<string,TYPE> m;
    map<string,TYPE> d;
    map<string,TYPE> t;
    map<string,TYPE> z;

public:
   int add_compt(COMPT compt,TYPE type,string index);
};


#endif //SRC_COMPONENT_H