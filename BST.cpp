#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node*left;
    node *right;
    node(int d){
        data=d;
        left=right=NULL;
    }
};

node *searchBST(node *root,int data){
    while(root!=NULL and root->data!=data){
        root = root->data>data? root->left:root->right;
    }
    return root;
}

int findCeil(node *root, int key){

	int ceil = -1; 
    while (root!=NULL) {

        if (root->data == key) {
            ceil = root->data;
            return ceil;
        }
 
        if (key > root->data) {
            root = root->right;
        }
        else {
            ceil = root->data; 
            root = root->left;
        }
    }
    return ceil; 
}

int floorInBST(node* root, int key)
{
    int floor = -1; 
    while (root!=NULL) {
 
        if (root->data == key) {
            floor = root->data;
            return floor;
        }
 
        if (key > root->data) {
            floor = root->data;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return floor;
}

node* insertIntoBST(node* root, int val) {
        if(root==NULL) return new node(val);
        if(val<root->data) root->left=insertIntoBST(root->left,val);
        if(val>root->data) root->right=insertIntoBST(root->right,val);
        return root;
}

int findminfromright(node* root){
        while(root->left!=nullptr)
            root=root->left;
        return root->data;
}
node* deleteNode(node* root, int key) {
        if(root==nullptr) return root;
        else if(root->data>key) root->left=deleteNode(root->left,key);
        else if(root->data<key) root->right=deleteNode(root->right,key);
        else{
            if(root->right==nullptr){
                return root->left;
            }else if(root->left==nullptr){
                return root->right;
            }else{
			    //replace the root value by find the minimum val from right side 
                root->data=findminfromright(root->right);
                root->right = deleteNode(root->right, root->data);
            }
        }
        return root;
}

node* inorderSuccessor(node* root, node* p) {
    node* successor = NULL;
        
    while (root != NULL) {
            
        if (p->data >= root->data) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }    
    return successor;
}

int main(){
    node *root = new node(8);
    root->left = new node(5);
    root->right = new node(12);
    root->left->left = new node(4);
    root->left->right = new node(7);
    root->right->left = new node(10);
    root->right->right = new node(14);
    root->left->right->left = new node(6);
    root->right->right->left = new node(13);
    return 0;
}