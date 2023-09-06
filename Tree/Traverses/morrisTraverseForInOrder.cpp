#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

Time Complexity:

Morris Traversal visits each node of the binary tree exactly once.
For each node, it performs constant time operations.
Therefore, the time complexity is O(n), where "n" is the number of nodes in the tree.
Space Complexity:

Morris Traversal uses only a constant amount of extra space (O(1)) to create threaded links between nodes.
It doesn't use any additional data structures like stacks or queues to store nodes.
Hence, the space complexity is O(1), indicating that it is a space-efficient traversal method.
Overall, Morris Traversal is particularly useful when you need to perform tree traversals without consuming a lot of additional memory, making it suitable for cases where memory efficiency is a concern.

*/

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:
    // Function to build a binary tree by level order
    void buildTreeByLevelOrder(Node*& root) {
        queue<Node*> q;

        cout << "Enter root data : " << endl;
        int data;
        cin >> data;
        root = new Node(data);
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            int leftNode;
            cout << "Enter left data of root : " << temp->data << endl;
            cin >> leftNode;

            if (leftNode != -1) {
                temp->left = new Node(leftNode);
                q.push(temp->left);
            }

            int rightNode;
            cout << "Enter right data of root : " << temp->data << endl;
            cin >> rightNode;

            if (rightNode != -1) {
                temp->right = new Node(rightNode);
                q.push(temp->right);
            }
        }
    }

    // Morris Inorder Traversal
    void morrisInorder(Node* root) {
        Node* current, * pre;

        if (root == NULL)
            return;

        current = root;

        while (current != NULL) {
            if (current->left == NULL) {
                cout << current->data << " ";
                current = current->right;
            }
            else {
                pre = current->left;

                while (pre->right != NULL && pre->right != current)
                    pre = pre->right;

                if (pre->right == NULL) {
                    pre->right = current;
                    current = current->left;
                }
                else {
                    pre->right = NULL;
                    cout << current->data << " ";
                    current = current->right;
                }
            }
        }
    }

    // Morris Preorder Traversal
    void morrisPreorder(Node* root) {
        Node* current, * pre;

        if (root == NULL)
            return;

        current = root;

        while (current != NULL) {
            if (current->left == NULL) {
                cout << current->data << " ";
                current = current->right;
            }
            else {
                pre = current->left;

                while (pre->right != NULL && pre->right != current)
                    pre = pre->right;

                if (pre->right == NULL) {
                    pre->right = current;
                    cout << current->data << " "; // Print before moving to left
                    current = current->left;
                }
                else {
                    pre->right = NULL;
                    current = current->right;
                }
            }
        }
    }

    // Morris Postorder Traversal
    void morrisPostorder(Node* root) {
        if (root == NULL)
            return;

        Node dummy(0);
        dummy.left = root;
        root = &dummy;

        Node* current = root;

        while (current != NULL) {
            if (current->left == NULL) {
                current = current->right;
            }
            else {
                Node* pre = current->left;

                while (pre->right != NULL && pre->right != current)
                    pre = pre->right;

                if (pre->right == NULL) {
                    pre->right = current;
                    current = current->left;
                }
                else {
                    pre->right = NULL;
                    reversePrint(current->left); // Reverse print the left subtree
                    current = current->right;
                }
            }
        }
    }

private:
    // Helper function to reverse print a subtree
    void reversePrint(Node* node) {
        if (node == NULL)
            return;
        stack<int> s;
        Node* current = node;

        while (current != NULL) {
            s.push(current->data);
            current = current->right;
        }

        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }
};

int main() {
    Solution solution;
    Node* root = NULL;

    int choice;
    while (true) {
        cout << "Menu: \n";
        cout << "1. Build Tree\n";
        cout << "2. Morris Inorder Traversal\n";
        cout << "3. Morris Preorder Traversal\n";
        cout << "4. Morris Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            solution.buildTreeByLevelOrder(root);
            break;
        case 2:
            cout << "Morris Inorder Traversal: ";
            solution.morrisInorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Morris Preorder Traversal: ";
            solution.morrisPreorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Morris Postorder Traversal: ";
            solution.morrisPostorder(root);
            cout << endl;
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
