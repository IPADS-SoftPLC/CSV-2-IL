#include "Component.h"
string get_type_string(TYPE type)
{
    switch (type)
    {
    case INT:
        return "INT";
    case DINT:
        return "DINT";
    case REAL:
        return "REAL";
    case BOOL:
        return "BOOL";
    case R_TRIG:
        return "R_TRIG";

    default:
        cout<<"[ERROR]: wrong type"<<endl;
        return "";
    }
}
int Component::add_compt(COMPT compt, TYPE type, string index)
{
    switch (compt)
    {
    case X:
        if (x.find(index) == x.end())
        {
            x.insert(pair<string, TYPE>(index, type));
        }
        else
        {
            /* 如果发现已经存了 检查一下类型是否一致 */
            if (x[index] != type)
            {
                cout << "[ERROR] : component type conflict" << endl;
            }
        }
        break;
    case T:
        if (t.find(index) == t.end())
        {
           t.insert(pair<string, TYPE>(index, type));
        }
        else
        {
            /* 如果发现已经存了 检查一下类型是否一致 */
            if (t[index] != type)
            {
                cout << "[ERROR] : component type conflict" << endl;
            }
        }
        break;

    case Y:
        if (y.find(index) == y.end())
        {
            y.insert(pair<string, TYPE>(index, type));
        }
        else
        {
            /* 如果发现已经存了 检查一下类型是否一致 */
            if (y[index] != type)
            {
                cout << "[ERROR] : component type conflict" << endl;
            }
        }
        break;

    case M:
        if (m.find(index) == m.end())
        {
            m.insert(pair<string, TYPE>(index, type));
        }
        else
        {
            /* 如果发现已经存了 检查一下类型是否一致 */
            if (m[index] != type)
            {
                cout << "[ERROR] : component type conflict"<< endl;
            }
        }
        break;

    case D:
        if (d.find(index) == d.end())
        {
            d.insert(pair<string, TYPE>(index, type));
        }
        else
        {
            /* 如果发现已经存了 检查一下类型是否一致 */
            if (d[index] != type)
            {
                cout << "[ERROR] : component type conflict" << endl;
            }
        }
        break;

    case Z:
        if (z.find(index) == z.end())
        {
            z.insert(pair<string, TYPE>(index, type));
        }
        else
        {
            /* 如果发现已经存了 检查一下类型是否一致 */
            if (z[index] != type)
            {
                cout << "[ERROR] : component type conflict" << endl;
            }
        }
        break;

    case K:
        if (k.find(index) == k.end())
        {
            k.insert(pair<string, TYPE>(index, type));
        }
        else
        {
            /* 如果发现已经存了 检查一下类型是否一致 */
            if (k[index] != type)
            {
                cout << "[ERROR] : component type conflict" << endl;
            }
        }
        break;

    default:
        cout << "[ERROR] :wrong component. compt:" <<compt << endl;
        return -1;
    }
    return 0;
}

void Component::output_var()
{
    map<string, TYPE>::iterator iter;
    iter = x.begin();
    while (iter != x.end())
    {
        cout << "X" << iter->first << ": " << get_type_string(iter->second) << endl;
        iter++;
    }

    iter = y.begin();
    while (iter != y.end())
    {
        cout << "Y" << iter->first << ": " << get_type_string(iter->second) << endl;
        iter++;
    }

    iter = t.begin();
    while (iter != t.end())
    {
        cout << "T" << iter->first << ": " << get_type_string(iter->second) << endl;
        iter++;
    }

    iter = m.begin();
    while (iter != m.end())
    {
        cout << "M" << iter->first << ": " << get_type_string(iter->second) << endl;
        iter++;
    }

    iter = k.begin();
    while (iter != k.end())
    {
        cout << "K" << iter->first << ": " << get_type_string(iter->second)<<":="<< iter->first<<endl;

        iter++;
    }
}

void Component::output_var_to_file(ofstream &outfile)
{
    map<string, TYPE>::iterator iter;
    iter = x.begin();
    outfile<<"\tVAR"<<endl;
    while (iter != x.end())
    {
        outfile << "\t\tX" << iter->first << ": " << get_type_string(iter->second)<<";" << endl;
        iter++;
    }

    iter = y.begin();
    while (iter != y.end())
    {
        outfile << "\t\tY" << iter->first << " : " << get_type_string(iter->second)<<";" << endl;
        iter++;
    }

    iter = t.begin();
    while (iter != t.end())
    {
        outfile  << "\t\tT" << iter->first << ": " << get_type_string(iter->second) <<";"<< endl;
        iter++;
    }

    iter = m.begin();
    while (iter != m.end())
    {
        outfile << "\t\tM" << iter->first << ": " << get_type_string(iter->second)<<";" << endl;
        iter++;
    }

    iter = k.begin();
    while (iter != k.end())
    {
        outfile << "\t\tK" << iter->first << ": " << get_type_string(iter->second)<<":="<< iter->first<<";" <<endl;
        iter++;
    }
    outfile<<"\tEND_VAR"<<endl;
    outfile<<endl;
}