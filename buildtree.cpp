#include<bits/stdc++.h>
using namespace std;

struct node
{
    /* data */
    int data;
    struct node* left;
    struct node* right;

    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
int search(int in[],int sin,int endin,int curr){
    for(int i=sin;i<=endin;i++){
        if(in[i]==curr) return i;
    }
    return -1;
}
void inorderprint(struct node* root){
    if(root==NULL) return; 
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}
/* build tree using peorder and inorder*/

// node* buildtree(int pre[],int in[],int sin,int endin){
//     static int idx=0;
//     if(sin>endin) return NULL;
//     int curr=pre[idx];
//     idx++;
//     node* Node=new node(curr);
//     if(sin == endin) return Node;

//     int pos=search(in,sin,endin,curr);
//     Node->left=buildtree(pre,in,sin,pos-1);
//     Node->right=buildtree(pre,in,pos+1,endin);
//     return Node;
// }
/* build tree using postorder and inorder */
node* buildtree(int post[],int in[],int st,int end){
    static int idx=end;
    if(st>end) return NULL;
    int curr=post[idx];
    idx--;
    node* root=new node(curr);
    int pos=search(in,st,end,curr);
    root->right=buildtree(post,in,pos+1,end);
    root->left=buildtree(post,in,st,pos-1);
    return root;
}
int main(){
    int pre[]={1,2,4,3,5};
    int in[]={4,2,1,5,3};
    int post[]={4,2,5,3,1};
    //struct node* t1=buildtree(pre,in,0,4);
    node* root=buildtree(post,in,0,4);
    inorderprint(root);
    return 0;
}