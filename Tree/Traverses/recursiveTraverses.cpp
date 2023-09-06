#include <iostream>
#include <queue>
#include <stack>

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


void LevelOrderTreeBuild(Node* &root){

    queue<Node*>q;
    cout<< "Enter the root data :"<< endl;
    int data;
    cin>> data;
    
    root = new Node(data);
    q.push(root);


    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout<<"Enter the left data for : " << temp->data << endl;
        int leftData;
        cin>> leftData;
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter the right data for : " << temp->data << endl;
        int rightData;
        cin>> rightData;
        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }

    }

}


Node* Tree_Creation(Node* root)
{
    cout<< "Enter the Data : " << endl;
    int data;
    cin>> data;
    root = new Node(data);

    // base case
    if(data == -1){
        return NULL;
    }

    cout<< " enter the data for inserting in left of : " << data << endl;
    root ->left = Tree_Creation(root->left);


    cout<< "enter the data for inserting in right of :  "<< data << endl;
    root ->right = Tree_Creation(root->right);


}


// NLR
void Inorder(Node *root)
{
    if(root == NULL){
        return ;
    }
    Inorder(root->left);
    cout<< root->data << " ";
    Inorder(root->right);
}


//  NLR
void preorder(Node *root)
{
    if(root == NULL){
        return ;
    }
    cout<< root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//  LRN
void postorder(Node *root)
{
    if(root == NULL){
        return ;
    }

    postorder(root->left);

    postorder(root->right);

    cout<< root->data << " ";
}

int main()
{
    Node* root =  NULL; 
    
    cout << "Enter the No. " << endl;

    while (true) {
    cout << " \n \n 1. Building tree with Recursion \t \t  2. Building tree with Level Order  \n \n  Traverse \n 3. Inorder \t \t 4. Pre-Order \t \t 5. Post-Order \n \n -1. Exit  \n \n " << endl;
    int ch;
    cin >> ch;

    switch (ch) {
        case 1:
            root = Tree_Creation(root);
            break;

        case 2:
            LevelOrderTreeBuild(root);
            break;

        case 3:
            Inorder(root);
            break;

        case 4:
            preorder(root);
            break;

        case 5:
            postorder(root);
            break;

        case -1:
            exit(-1);
            break;
        }
    }



    return 0;
}

