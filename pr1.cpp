#include<iostream>
#include<string.h>
using namespace std;
class TelephoneDirectory
{
    public:
        int Phoneno;
        string name;
    void Display()
    {
        cout << Phoneno << " ";
        cout << name << " ";
        cout << endl;
    }
};
class Hashing
{
    public:
        int size = 10;
        TelephoneDirectory *TD = new TelephoneDirectory[size];
    Hashing()
    {
        int counter=0;
        for(counter = 0; counter < size; counter++)
        {
            TD[counter].Phoneno = 0;
            TD[counter].name = "-----";
        }
    }
    void AddRecord(string nem, int Pno, int ch)
    {
        int index;
        index = DivisionMethod(Pno);
        if(TD[index].name=="-----")
        {
            TD[index].name = nem;
            TD[index].Phoneno = Pno;
        }
        else
        {
         if(ch==1)
            LinearProbing(nem, Pno, index);
        else
            QuadraticProbing(nem, Pno, index);
        }
    }
    int DivisionMethod(int pno)
    {
        return (pno % size);
    }
    void LinearProbing(string nem, int pno,int index)
    {
        while(TD[index].name != "-----")
        index = (index + 1) % size;
        TD[index].name = nem;
        TD[index].Phoneno = pno;
    }
    void QuadraticProbing(string nem, int pno,int index)
    {
        int i=1;
        while(TD[index].name != "-----")
        {
            index = (index + i*i) % size;
            i++;
        }
        TD[index].name = nem;
        TD[index].Phoneno = pno;
    }
    void Search(string nem, int Pno)
    {
        int index,idx=0;
        index = DivisionMethod(Pno);
        while(idx<=size)
        {
            if(TD[index].name == nem)
            {
                cout<<"Record found at "<<index<< " index"<<endl;
                break;
            }
            index = (index + 1) % size;
            idx++;
        }
        if(idx>size)
        {
            cout<<"Record Not found "<<endl;
        }
    }
    void Display()
    {
        int counter=0;
        cout << "Telephone Directory HashTable - " << endl;
        cout << "================================" << endl<< endl;
        for(counter = 0; counter < size; counter++)
        {
            cout << counter << " | ";
            TD[counter].Display();
        }
    }
};
int main()
{
 Hashing hsh;
 int choice = 0;
 int Pno;
 string nem;
 do
 {
    cout<< "======Menu====="<<endl;
    cout<< "1. Add Record"<<endl;
    cout<< "2. Search"<<endl;
    cout<< "3. Display"<<endl;
    cout<< "4. Exit"<<endl;
    cout<< "Enter choice : ";
    cin>>choice;
    if(choice<3)
    {
        cout<< "Enter Name : ";
        cin>>nem;
        cout<< "Enter Phone no.:";
        cin>>Pno;
    }
    switch (choice)
    {
        case 1:
        cout<< "1. Linear or 2. Quadratic Probing";
        cin>>choice;
        hsh.AddRecord(nem,Pno,choice);
        choice=1;
        break;
        case 2:
        hsh.Search(nem, Pno);
        break;
        case 3:
        hsh.Display();
        break;
        case 4:
        cout<< "Good Bye!!!, Have A Nice Day."<<endl;
        break;
        default:
        cout<< "Enter Proper Choice!!!"<<endl;
    }
}while(choice<4);

}