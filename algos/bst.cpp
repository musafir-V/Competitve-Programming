#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *left, *right;
};

node* NewNode(int val, node *left=NULL, node *right=NULL) {
    node *temp=new node;
    temp->data=val;
    temp->left=left;
    temp->right=right;
    return temp;
}

node* insert(node* root, int val) {
    if(root==NULL) return NewNode(val);
    else if(root->data > val) {root->left=insert(root->left,val);}
    else if(root->data < val) {root->right=insert(root->right,val);}
    return root;
}

int findMin(node* root) {
    if(root->left==NULL) return root->data;
    else return findMin(root->left);
}

node* remove(node *root, int val) {
    if(root==NULL) return root;
    else if(root->data > val) {root -> left = remove(root -> left, val); return root;}
    else if(root->data < val) {root -> right = remove(root -> right, val); return root;}
    else {
        if(root->left==NULL) {
            node *temp=root;
            root=root->right;
            delete temp;
            return root;
        } else if(root->right==NULL) {
            node *temp=root;
            root=root->left;
            delete temp;
            return root;
        } else {
            int min=findMin(root->right);
            root->data=min;
            root->right=remove(root->right,min);
            return root;
        }
    }
}

bool search(node* root, int val) {
    if(root==NULL) return false;
    else if(root->data > val) return search(root->left,val);
    else if(root->data < val) return search(root->right,val);
    return true;
}

void inorder(node* root) {
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    node *root=NULL;
    root=insert(root,5);
    root=insert(root,4);
    root=insert(root,15);
    cout<<search(root,5)<<" ";
    // inorder(root);
}
