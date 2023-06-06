#include<iostream>
using namespace std;
class set
{
private:
int s_index, capacity=0;
char *set_arr;
public:
set(int cap)
{
s_index = 0;
capacity = cap;
set_arr = new char(capacity);
}
void Add(char S)
{
if(!isFull() && !isMember(S))
{
set_arr[s_index]=S;
s_index++;
}
}
bool isFull()
{
if(s_index>=capacity)
{
cout <<"Set is Full!!!, Cannot Add elements\n";
return true;
}
return false;
}
void Remove(char S)
{
char *arr_copy = new char(capacity);
int idx=0;
for(int counter=0; counter<=s_index;counter++)
{
if(set_arr[counter] != S)
{
arr_copy[idx]= set_arr[counter];
idx++;
}
}
set_arr = arr_copy;
}
void Union(set *A)
{
int counter=0;
cout<<"\n{";
for(counter=0; counter <=this->s_index;counter++) {
cout <<this->set_arr[counter]<<", ";
}
cout<<"\n";
counter=0;
while(counter <= A->s_index)
{
if(!this->isMember(A->set_arr[counter]))
cout<<A->set_arr[counter]<<",";
counter++;
}
cout<<"}\n";
}
void Intersection(set *A)
{
int counter=0,size=0;
set *set_A, *set_B;
cout<<"\n{";
if (this->s_index < A->s_index)
{
size=A->s_index;
set_A = A;
set_B = this;
}
else
{
size=this->s_index;
set_A = this;
set_B = A;
}
while(counter<=size)
{
if(set_B->isMember(set_A->set_arr[counter]) && set_A->set_arr[counter]!='\0')
cout << set_A->set_arr[counter]<<",";
counter++;
}
cout<<"}\n";
}
void Difference(set *A)
{
int counter=0;
cout<<"\n{";
while(counter<=this->s_index)
{
if(!A->isMember(this->set_arr[counter]) && this->set_arr[counter]!='\0')
cout << this->set_arr[counter]<<",";
counter++;
}
cout<<"}\n";
}
int Size()
{
return this->s_index;
}
bool isMember(char S)
{
for(int counter=0; counter <= s_index;counter++)
{
if(set_arr[counter] == S)
return true;
}
return false;
}
void Display()
{
cout << "{";
for(int counter=0; counter<=s_index;counter++)
{
cout << set_arr[counter] << ", ";
}
cout << "}\n";
}
};
int main() {
set *set_A = new set(10);
set *set_B = new set(10);
int ans=0, choice=0;
char element=' ';
do
{
cout <<"**** Menu for Set operations ****\n";
cout <<"1. Add Element\n";
cout <<"2. Remove Element\n";
cout <<"3. Search Element\n";
cout <<"4. Display Elements\n";
cout <<"5. Union\n";
cout <<"6. Intersection\n";
cout <<"7. Difference\n";
cout <<"8. Size of set\n";
// cout <<"9. Subset \n";
cout <<"9. Exit\n";
cout <<"Enter option : ";
cin >> choice;
if(choice<4)
{
cout <<"Enter Element : ";
cin >> element;
cout <<"Set A or Set B : (1/2) : ";
cin >> ans;
}
switch(choice)
{
case 1:
if(ans == 1)
set_A->Add(element);
else
set_B->Add(element);
break;
case 2:
if(ans == 1)
set_A->Remove(element);
else
set_B->Remove(element);
break;
case 3:
if(set_A->isMember(element)==true)
cout <<"Element Found \n";
else
cout <<"Element Not Found \n";
break;
case 4:
cout <<"Elements of Set A:";
set_A->Display();
cout <<"Elements of Set B:";
set_B->Display();
break;
case 5:
cout <<"Union of Set A & Set B : ";
set_A->Union(set_B);
break;
case 6:
cout <<"Intersection of Set A & Set B : ";
set_A->Intersection(set_B);
break;
case 7:
cout <<"Difference of {A - B} : ";
set_A->Difference(set_B);
cout <<"Difference of {B - A} : ";
set_B->Difference(set_A);
break;
case 8:
cout <<"Size of set A : "<<set_A->Size()<<endl;
cout <<"Size of set B : "<<set_B->Size()<<endl;
break;
case 9:
cout <<"Good Bye!!! Have A Nice Day\n";
break;
default :
cout <<"Enter proper option!!\n";
choice=0;
}
}while(choice<9);
return 0;
}

