#include <iostream>
#include <queue>


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


int main ()
{
    Node * root = NULL;

    LevelOrderTreeBuild(root);

    return 0;
}