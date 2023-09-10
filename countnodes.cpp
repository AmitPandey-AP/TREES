#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
int countnodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return countnodes(root->left)+countnodes(root->right)+1;
}

/* sum all nodes*/
int sumnodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return sumnodes(root->left)+sumnodes(root->right)+root->data;
}
int32_t main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    cout<<countnodes(root)<<" ";
    cout<<sumnodes(root);
    return 0;
}