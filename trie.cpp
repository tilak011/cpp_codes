#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};
class Trie{
    public:
        TrieNode *root;
        Trie(){
            root= new TrieNode('\0');
        }
        void insert(TrieNode* root , string word){
            //base case
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }
            int index=word[0]-'A';
            TrieNode* child;
            if(root->children[index]!=nullptr){
                child=root->children[index];
            }else{
                child=new TrieNode(word[0]);
                root->children[index]=child;
            }
            insert(child,word.substr(1));
        }
        void insertt(string word){
            insert(root,word);
        }
};

int main(){
    Trie *t=new Trie();
    t->insertt("abcdef");

    return 0;
}