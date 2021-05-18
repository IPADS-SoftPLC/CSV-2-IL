#include "Component.h"

int Component::add_compt(COMPT compt,TYPE type,string index)
{
    switch (compt)
    {
    case X:
        if(x.find(index)==x.end())
        {
            x.insert(pair<string,TYPE>(index,type));
        }
        break;
    
    case Y:
        if(y.find(index)==y.end())
        {
            y.insert(pair<string,TYPE>(index,type));
        }
        break;

    case M:
        if(m.find(index)==m.end())
        {
            m.insert(pair<string,TYPE>(index,type));
        }
        break;
    
    case D:
        if(d.find(index)==d.end())
        {
            d.insert(pair<string,TYPE>(index,type));
        }
        break;
    
    case Z:
        if(z.find(index)==z.end())
        {
            z.insert(pair<string,TYPE>(index,type));
        }
        break;

    
    default:
        break;
    }
}