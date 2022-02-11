#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int d){
        data=d;
        left=right=NULL;
    }
};

class Solution {
public:
    node* lowestCommonAncestor(node* root, node* p, node* q) {
        //base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        node* left = lowestCommonAncestor(root->left, p, q);
        node* right = lowestCommonAncestor(root->right, p, q);

        //result
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else { //both left and right are not null, we found our result
            return root;
        }
    }
};

int main(){
    node *root = new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    root->left->left->left=new node(8);
    root->left->left->right=new node(9);
    root->left->right->left=new node(10);
    root->left->right->right=new node(11);
    root->right->left->left=new node(12);
    root->right->left->right=new node(13);
    root->right->right->left=new node(14);
    Solution obj;
    cout<<obj.lowestCommonAncestor(root,root->right->left->right,root->right->right->left)->data<<endl; //lca(root,13,14). Ans must be 3
    return 0;
}