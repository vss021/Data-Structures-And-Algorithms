#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to perform the left view of a binary tree
void rightViewUtil(vector<int>& result, Node* root, int lvl) {
    if (root == NULL) return;

    // Check if this is the first node at the current level
    if (lvl == result.size())
        result.push_back(root->data);

    // Then, traverse the right subtree
    rightViewUtil(result, root->right, lvl + 1);
    
    // Traverse the left subtree first to find the leftmost node
    rightViewUtil(result, root->left, lvl + 1);
}

// Function to find the left view of a binary tree
vector<int> rightView(Node* root) {
    vector<int> result;
    rightViewUtil(result, root, 0);
    return result;
}

// Function to create a new node in the binary tree
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    // Create a sample binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Find and print the left view of the binary tree
    vector<int> rightViewResult = rightView(root);
    cout << "Left View of the Binary Tree: ";
    for (int i = 0; i < rightViewResult.size(); i++) {
        cout << rightViewResult[i] << " ";
    }
    cout << endl;

    return 0;
}
