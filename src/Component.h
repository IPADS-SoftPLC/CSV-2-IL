#ifndef SRC_COMPONENT_H
#define SRC_COMPONENT_H

#include <vector>
#include <map>
using namespace std;

enum COMPT{
    X,Y,D,M,K,T,Z
};

enum TYPE{
    INT,REAL,BOOL,
};

class Component {
private:
    map<int,TYPE> x;
    map<int,TYPE> y;
    map<int,TYPE> m;
    map<int,TYPE> d;
    map<int,TYPE> t;
    map<int,TYPE> z;

public:
   int add_compt(COMPT compt,TYPE type,int index);
};

int Component::add_compt(COMPT compt,TYPE type,int index)
{
    switch (compt)
    {
    case X:
        if(x.find(index)==x.end())
        {
            x.insert(pair<int,TYPE>(index,type));
        }
        break;
    
    case Y:
        if(y.find(index)==y.end())
        {
            y.insert(pair<int,TYPE>(index,type));
        }
        break;

    case M:
        if(m.find(index)==m.end())
        {
            m.insert(pair<int,TYPE>(index,type));
        }
        break;
    
    case D:
        if(d.find(index)==d.end())
        {
            d.insert(pair<int,TYPE>(index,type));
        }
        break;
    
    case Z:
        if(z.find(index)==z.end())
        {
            z.insert(pair<int,TYPE>(index,type));
        }
        break;

    
    default:
        break;
    }
}
#endif //SRC_COMPONENT_H