/*
trie also calles as Retiev data structure 

trie are used for 
    -> search 
    -> store large data
    -> trie root data is empty alway's

Trie Root Node will be NUll Pointer's
Trie data contains 3 thing's
    
    -> data (char)
    -> list of charector's linked 
    -> check node is leaf node(means ending of list) true or false

        Why? we need to check for isLeaf node
            -> because of easy to search in trie 
        Example :
            if we add the string like 
                store string => "abcdef"
                search string => abc 

                abc is present in the trie but the ending point denotd the one string is ended here 
                that's why we check isleaf node or not

*/

#include <iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isLeafNode;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isLeafNode = false;
    }

};

// class for trie

class Trie{
    public:
    // root pointer
    TrieNode * root;
    // first data in the trie will be null character
    Trie(){
        root = new TrieNode('\0');
    }

    // insertion Function
    //  -> helper function a
    //  -> insert funcrion

    void insertFunction(TrieNode* root, string word)
    {
        /* we implement this function by recursive approch
        */

        // base case

        if(word.size() == 0){
            root->isLeafNode = true;
            return; 
        }

        // find index

        int index = word[0]-'a';

        TrieNode* child;

        // if word[0] elemtn is present then
        if(root->children[index] != NULL){
            // point to word[0]
            child = root->children[index];
        }
        else{
            // inset element into index of children
            /*
            this is not a tree or linked list
            root->children[index] = word[0];
            child = root->children[index];
            */ 
            
            // step1:
            // create new trie
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursive call forn word second char

        insertFunction(child, word.substr(1));

    }

    void insertHeapler(string word){
        insertFunction(root, word);
    }

// Searching 
    bool searchUtill(TrieNode* root, string word){
        // base case

        if(word.length() == 0){
            return root->isLeafNode;
        }

        int index = word[0]-'a';
        TrieNode* child;

        // present 
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            // absent
            return false;
        }

        return searchUtill(child, word.substr(1));
    }
    bool searchWord(string word){

        return searchUtill(root, word);
    }

    

};




int main()
{
    Trie* top = new Trie();
    top-> insertHeapler("abcd");
    cout << "Inseted element " << endl;
    
    if(top->searchWord("abcd")){
        cout << "Element is present " << endl;
    }else{
        cout << "Element is not  present " << endl;
    }

    return 0;
}