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

int maxSum(node* root, int& ans) {
    /* This function return the Branch Sum......
    So if the node is NULL then it won't have a branch....so the branch sum will be 0.
    */
    //Base Case
    if(root == NULL){
        return 0;
    }
    
    //Recursive Case 
    //BS = Branch Sum
    int leftBS = root->data + maxSum( root->left , ans );
    int rightBS = root->data + maxSum( root->right , ans );
    
    ans = max({
                ans,            //we may have found the maximum ans already
                root->data,      //may be the current root data is the maximum sum possible
                leftBS,         //may be the answer contain root->data + left branch value
                rightBS,        //may be the answer contain root->data + right branch value
                leftBS + rightBS - root->data   // may be ans conatin left branch + right branch + root->data
                                               // Since the root data is added twice from leftBS and rightBS so we are sunstracting it.
            });
    
    //Return the max branch Sum
    return max({ leftBS , rightBS , root->data });
}

int maxPathSum(node* root) {
    int ans = INT_MIN;
    maxSum(root, ans);
    return ans;
}

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
    cout<<"Max Path Sum = "<<maxPathSum(root);
    return 0;
}