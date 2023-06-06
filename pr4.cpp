#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

class BinarySearchTree {
public:
    node* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        node** curr = &root;
        while (*curr != nullptr) {
            if (value < (*curr)->data)
                curr = &(*curr)->left;
            else
                curr = &(*curr)->right;
        }
        *curr = new node{value, nullptr, nullptr};
    }

    int findHeight(node* root) {
        if (root == nullptr)
            return -1;
        return max(findHeight(root->left), findHeight(root->right)) + 1;
    }

    int findMinValue(node* root) {
        while (root->left != nullptr)
            root = root->left;
        return root->data;
    }

    void mirrorTree(node* root) {
        if (root == nullptr)
            return;
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
    }

    bool searchValue(node* root, int value) {
        if (root == nullptr)
            return false;
        if (root->data == value)
            return true;
        if (value < root->data)
            return searchValue(root->left, value);
        return searchValue(root->right, value);
    }

    void inorderTraversal(node* root) {
        if (root == nullptr)
            return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    void preorderTraversal(node* root) {
        if (root == nullptr)
            return;
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    void postorderTraversal(node* root) {
        if (root == nullptr)
            return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
};

int main() {
    BinarySearchTree bst;
    int choice, value;
    char ans;

    do {
        cout << "1) Insert new node" << endl;
        cout << "2) Number of nodes in longest path from root" << endl;
        cout << "3) Minimum data value in the tree" << endl;
        cout << "4) Change tree nodes' left and right pointers" << endl;
        cout << "5) Search a value" << endl;
        cout << "6) Inorder traversal" << endl;
        cout << "7) Preorder traversal" << endl;
        cout << "8) Postorder traversal" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            bst.insert(value);
            break;
        case 2:
            cout << "Number of nodes in the longest path from root: " << bst.findHeight(bst.root) << endl;
            break;
        case 3:
            cout << "Minimum data value in the tree: " << bst.findMinValue(bst.root) << endl;
            break;
        case 4:
            bst.mirrorTree(bst.root);
            cout << "Tree after swapping left and right pointers: ";
            bst.inorderTraversal(bst.root);
            cout << endl;
            break;
        case 5:
            cout << "Enter the value to search: ";
            cin >> value;
            if (bst.searchValue(bst.root, value))
                cout << "Value found in the tree." << endl;
            else
                cout << "Value not found in the tree." << endl;
            break;
        case 6:
            cout << "Inorder traversal: ";
            bst.inorderTraversal(bst.root);
            cout << endl;
            break;
        case 7:
            cout << "Preorder traversal: ";
            bst.preorderTraversal(bst.root);
            cout << endl;
            break;
        case 8:
            cout << "Postorder traversal: ";
            bst.postorderTraversal(bst.root);
            cout << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> ans;
        cout << endl;

    } while (ans == 'y' || ans == 'Y');

    return 0;
}
