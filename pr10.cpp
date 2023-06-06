#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class tel
{
public:
    int rollNo;
    char name[10];
    char div;
    char address[20];

    void accept()
    {
        cout << "\n\tEnter Roll Number: ";
        cin >> rollNo;
        cout << "\n\tEnter the Name: ";
        cin >> name;
        cout << "\n\tEnter the Division: ";
        cin >> div;
        cout << "\n\tEnter the Address: ";
        cin >> address;
    }

    void show()
    {
        cout << "\n\t" << rollNo << "\t\t" << name << "\t\t" << div << "\t\t" << address;
    }
};

int main()
{
    int ch;
    tel t1;

    do
    {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>MENU<<<<<<<<<<<<<<<<<<<<";
        cout << "\n1. Insert and overwrite\n2. Show\n3. Delete\n4. Exit";
        cout << "\nEnter the Choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
            {
                ofstream f("StuRecord.txt", ios::out);
                if (!f)
                {
                    cout << "Error opening file";
                    break;
                }

                char choice;
                do
                {
                    t1.accept();
                    f.write((char*)&t1, sizeof(t1));

                    cout << "\nDo you want to enter more records? (Y/N): ";
                    cin >> choice;
                } while (choice == 'Y' || choice == 'y');

                f.close();
                break;
            }

            case 2:
            {
                ifstream f("StuRecord.txt", ios::in);
                if (!f)
                {
                    cout << "Error opening file";
                    break;
                }

                cout << "\n\tRoll No.\t\tName\t\tDivision\t\tAddress";
                while (f.read((char*)&t1, sizeof(t1)))
                {
                    t1.show();
                }

                f.close();
                break;
            }

            case 3:
            {
                int rollNoToDelete;
                cout << "\nEnter the Roll Number to delete: ";
                cin >> rollNoToDelete;

                ifstream fin("StuRecord.txt", ios::in);
                if (!fin)
                {
                    cout << "Error opening file";
                    break;
                }

                ofstream temp("temp.txt", ios::out);
                bool found = false;

                while (fin.read((char*)&t1, sizeof(t1)))
                {
                    if (t1.rollNo != rollNoToDelete)
                    {
                        temp.write((char*)&t1, sizeof(t1));
                    }
                    else
                    {
                        found = true;
                    }
                }

                fin.close();
                temp.close();

                if (found)
                {
                    remove("StuRecord.txt");
                    rename("temp.txt", "StuRecord.txt");
                    cout << "Record deleted successfully.";
                }
                else
                {
                    remove("temp.txt");
                    cout << "Record not found.";
                }

                break;
            }

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice. Please try again.";
                break;
        }

    } while (ch != 4);

    return 0;
}
