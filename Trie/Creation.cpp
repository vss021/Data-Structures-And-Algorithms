#include <bits/stdc++.h>

using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }
/*
insertion 
tc => O(length of word)

searching 
tc => o(length of word)
*/
    void insertUtill(TrieNode* root, string word){

            // base case

        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }

        // assumption word will be in capital
        int index = word[0] -'a';
        TrieNode* child;

        // present in trie
        if(root -> children[index] != NULL){
            child = root->children[index];
        }
        else{
            // absent in trie
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        // next will handle recurion

        insertUtill(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtill(root, word);
    }



    bool searchUtill(TrieNode* root, string word){
        // base case

        if(word.length() == 0){
            return root->isTerminal;
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


/* delete node from trie

step 1:
        -> search node in trie


step 2:
        -> if node exit 
        -> go to last index of word 
        -> isTerminal = false
*/


};

int main()
{
    Trie* t = new Trie();
    // cout << "abcd add " << endl;
    t->insertWord("arm");
    t->insertWord("do");
    t->insertWord("time");

    // cout << "abcd seraching " << endl;
    cout << "present or Not " << t->searchWord("arm") << endl;
    cout << "present or Not " << t->deleteWord("arm") << endl;
    cout << "present or Not " << t->searchWord("do") << endl;
    cout << "present or Not " << t->searchWord("time") << endl;
   
    // cout << "Search word Time " << t->searchUtill("do") << endl;

    return 0;
}