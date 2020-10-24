#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    int ending;
    TrieNode *childs[26];
    TrieNode() {ending = 0;for(int i=0;i<26;i++) childs[i]=NULL;}
};

struct Trie {
    TrieNode *root;
    Trie() {root = new TrieNode();}
    void insert(string s) {
        TrieNode *temp = root;
        for(auto i: s) {
            if(temp->childs[i-'a']==NULL) 
                temp->childs[i-'a'] = new TrieNode();
            temp = temp->childs[i-'a'];
        }
        temp->ending++;
    }
    bool search(string s) {
        TrieNode *temp = root;
        for(auto i: s) {
            if(temp->childs[i-'a']==NULL) return false;
            temp=temp->childs[i-'a'];
        }
        return temp!=NULL && temp->ending > 0;
    }
};



int main() {
    Trie *root = new Trie();
    root->insert("Hello");
    cout<<root->search("Hell");
    cout<<root->search("Hello");
}
