#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data =  data;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* buildWithRec(Node* root)
{
    cout<< "Enter the Data (exit for -1 left to right) : " << endl;
    int data;
    cin>> data;
    root = new Node(data);

    // base case
    if(data == -1){
        return NULL;
    }

    cout<< " enter the data for inserting in left of : " << data << endl;
    root ->left = buildWithRec(root->left);


    cout<< "enter the data for inserting in right of :  "<< data << endl;
    root ->right = buildWithRec(root->right);

}


int main()
{
    Node* root =  NULL; 
    root = buildWithRec(root);


    return 0;

}