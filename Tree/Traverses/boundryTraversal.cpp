#include <iostream>
#include <vector>
using namespace std;

/* A binary tree Node */
struct Node {
    int data;
    Node* left, * right;
};

class Solution {
private:
    
    void TraverseLeft(Node *root, vector <int> &result)
    {
        
        if( (root == NULL ) || (root->left == NULL && root->right == NULL) )
            return ;
        
        result.push_back(root->data);
        
        if(root->left)
            TraverseLeft(root->left, result);
        else
            TraverseLeft(root->right, result);
            
    }
    
    
    void TraverseLeaf(Node* root, vector <int> &result)
    {
        if(root == NULL)
            return ;
        
        if(root->left == NULL && root->right == NULL){
            result.push_back(root->data);
            return ;
        }
        
        TraverseLeaf(root->left, result);
        
        TraverseLeaf(root->right, result);
        
    }
    
    
    
    void TraverseRight(Node* root, vector <int>& result)
    {
        if( (root == NULL)|| (root->left == NULL && root->right == NULL)){
            // if(root->left == NULL && root->right == NULL)
                // result.push_back(root->data);
            return ;
        }
        
        if(root->right)
            TraverseRight(root->right, result);
            
        else
            TraverseRight(root->left, result);
        
        result.push_back(root->data);
    }
    
    
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector <int> result;
        
        if(root == NULL){
            return result;
        }
        
        result.push_back(root->data);
        
        // left part
        
        TraverseLeft(root->left, result);
        
        // left Subtree Nodes
        TraverseLeaf(root-> left, result);
        
        // right Subtree
        TraverseLeaf(root-> right, result);
        
        // right parts;
        TraverseRight(root->right, result);
        
        return result;
        
    }
};

// Function to create a new node in the binary tree
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    // Create a sample binary tree
    Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right->right = newNode(25);

    Solution solution;
    
    // Find and print the boundary of the binary tree
    vector<int> boundaryResult = solution.boundary(root);
    cout << "Boundary of the Binary Tree: ";
    for (int i = 0; i < boundaryResult.size(); i++) {
        cout << boundaryResult[i] << " ";
    }
    cout << endl;

    return 0;
}
