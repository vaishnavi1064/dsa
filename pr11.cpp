#include<iostream>
#include<fstream>
using namespace std;
int main()
{
 cout<<"\n\n ------*** Program to implement Random/Direct Access Files ***------\n\n";
 
 ofstream fout;
 
 fout.open("One.txt" , ios::out);
 cout<<"\n Writting into the file.....\n";
 
 cout<<"\n Location: "<<fout.tellp();
 cout<<" Line 01: Hello Dude, This is Sam...!!!";
 fout<<"Hello Dude, This is Sam...!!!"<<endl;
 
 cout<<"\n Location: "<<fout.tellp();
 cout<<" Line 02: Would you like to be my Friend..?";
 fout<<"Would you like to be my Friend..?"<<endl;
 
 cout<<"\n Location: "<<fout.tellp();
 cout<<" Line 03: We will enjoy together...!!!";
 fout<<"We will enjoy together...!!!"<<endl;
 
 cout<<"\n Location: "<<fout.tellp()<<endl;
 fout.close();
 ifstream fin;
 
 fin.open("One.txt" , ios::in);
 cout<<"\n Reading from the file.....\n";
 
 cout<<"\n Location: "<<fin.tellg();
 cout<<"\n Shift control to...";
 fin.seekg(64 , ios::beg);
 cout<<"\n Location: "<<fin.tellg();
 cout<<" Reading.... ";
 char c;
 while(!fin.eof())
 {
 fin.get(c);
 cout<<c;
 }
 cout<<"\n Conclusion: We have Directly Accessed the line-03 of the file.";
 fin.close();
 
 return 0;
}