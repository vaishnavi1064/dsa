#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream obj("one.txt");
    cout<<obj.tellp()<<endl;
    obj<<"Hello world";
    cout<<obj.tellp()<<endl;
    obj.seekp(-5,ios::end);
    cout<<obj.tellp()<<endl;
    obj<<"today";
    obj.close();
    
    ifstream obj1("one.txt");
    cout<<obj1.tellg()<<endl;
    obj1.seekg(6,ios::beg);
    cout<<obj1.tellg()<<endl;
    
    char c;
    while(!obj1.eof())
    {
        obj1.get(c);
        if(obj1.eof())
        {
            break;
        }
        cout<<c;
    }
    obj1.close();
}
