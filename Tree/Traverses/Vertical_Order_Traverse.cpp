#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void buildTreeByLevelOrder(Node* &root)
{
    queue<Node*>q;

    cout << "Enter root data : " << endl;
    int data;
    cin>> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        int leftNode;
        cout << "Enter left data of root : " << temp->data << endl;
        cin >> leftNode;

        if(leftNode != -1)
        {
            temp->left = new Node(leftNode);
            q.push(temp->left);
        }

        int rightNode;
        cout << "Enter right data of root : " << temp->data << endl;
        cin >> rightNode;

        if(rightNode != -1)
        {
            temp->right = new Node(rightNode);
            q.push(temp->right);
        }

    }
}

void verticalOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    unordered_map< int, vector< int > >  mapping;
    //             -> hd    -> vector 
    queue< pair < Node*, pair<int, int > > > q;
    //              -> data ,       -> hd, -> level

    q.push(make_pair(root, make_pair(0, 0)));

    // level order traverse

    while(!q.empty())
    {
        pair < Node*, pair<int, int > >  temp = q.front();
        q.pop();
        Node* currNode = temp.first;

        int hd = temp.second.first;

        int level = temp.second.second;

        // pushing data into mapping

        mapping[hd].push_back(currNode->data);

        if(currNode->left)
        {
            q.push(make_pair(currNode->left, make_pair(hd-1, level+1)));
        }  
        if(currNode->right)
        {
            q.push(make_pair(currNode->right, make_pair(hd+1, level+1)));
        }  

    }

    for(auto x : mapping)
    {
        for (auto j : x.second)
        {
            cout << j<< " ";
        }
        cout << endl;
    }

}

int main(){
    Node* root = NULL;
    buildTreeByLevelOrder(root);

    verticalOrderTraversal(root);
    return 0;
}