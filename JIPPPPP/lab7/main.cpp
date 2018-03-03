#include <iostream>
#include <vector>
#include <string>
using namespace std;
template <typename T>
int fun(vector <T> vec)
{
        if(vec.empty())
        {
            cout<<"Error"<<endl;
            return -1;
        }
        else
        {
            int index=0;
            T help=vec[0];
            for(int i=1;i<vec.size();i++)
            {
                if(vec[i]>help)
                {
                    index=i;
                    help=vec[i];
                }
            }
            return index;
        }


}
template<>
fun(vector <string> vec)
{
    if(vec.empty())
    {
        cout<<"Error"<<endl;
        return -1;
    }
    else
    {
        string help=vec[0];
        int index=0;
        for(int i(0);i<vec.size();i++)
        {
            if(help.compare(vec[i])<0)
            {
                help=vec[i];
                index=i;
            }
        }
        return index;
    }
}

int main()
{
    vector <string> svec={"aaa","aaaa","aaab"};
    vector <double> dvec={14.88,21.37,19.97};
    vector <int> ivec={14,21,19};
    cout<<fun(svec)<<endl;
    cout<<fun(dvec)<<endl;
    cout<<fun(ivec)<<endl;
    dvec.push_back(99.99);
    ivec.push_back(99);
    svec.push_back("grater");
    cout<<fun(dvec)<<endl;
    cout<<fun(ivec)<<endl;
    cout<<fun(svec)<<endl;
    return 0;
}


