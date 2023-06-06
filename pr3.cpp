#include <iostream>
using namespace std;

// Structure to represent a node in the tree
struct node
{
    char label[10];           // Label for the node (book, chapter, section)
    int ch_count;             // Number of child nodes
    struct node* child[10];   // Array to store child nodes
} *root;

// Class to implement the General Tree
class GT
{
public:
    void create_tree();       // Function to create the tree
    void display(node* r1);   // Function to display the tree

    GT()
    {
        root = NULL;
    }
};

// Function to create the tree
void GT::create_tree()
{
    int tbooks, tchapters, i, j, k;
    root = new node;
    cout << "Enter name of book: ";
    cin >> root->label;
    cout << "Enter no. of chapters in book: ";
    cin >> tchapters;
    root->ch_count = tchapters;
    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;
        cout << "Enter Chapter name: ";
        cin >> root->child[i]->label;
        cout << "Enter no. of sections in Chapter " << root->child[i]->label << ": ";
        cin >> root->child[i]->ch_count;
        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter Section " << j + 1 << " name: ";
            cin >> root->child[i]->child[j]->label;
        }
    }
}

// Function to display the tree
void GT::display(node* r1)
{
    int i, j, k, tchapters;
    if (r1 != NULL)
    {
        cout << "\n-----Book Hierarchy---";
        cout << "\n Book title: " << r1->label;
        tchapters = r1->ch_count;
        for (i = 0; i < tchapters; i++)
        {
            cout << "\n  Chapter " << i + 1;
            cout << " " << r1->child[i]->label;
            cout << "\n Sections";
            for (j = 0; j < r1->child[i]->ch_count; j++)
            {
                cout << "\n  " << r1->child[i]->child[j]->label;
            }
        }
    }
}

int main()
{
    int choice;
    GT gt;
    while (1)
    {
        cout << "-----------------" << endl;
        cout << "Book Tree Creation\n1. Create\n2. Display\n3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            gt.create_tree();
            break;
        case 2:
            gt.display(root);
            break;
        case 3:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}
