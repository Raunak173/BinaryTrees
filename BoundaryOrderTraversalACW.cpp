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
    bool isLeaf(node* root) {
        return !root->left && !root->right;
    }
    
    void addLeftBoundary(node* root, vector<int> &res) {
        node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) res.push_back(cur->data);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    void addRightBoundary(node* root, vector<int> &res) {
        node* cur = root->right;
        vector<int> tmp;
        while (cur) {
            if (!isLeaf(cur)) tmp.push_back(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for (int i = tmp.size()-1; i >= 0; --i) {
            res.push_back(tmp[i]);
        }
    }
    
    void addLeaves(node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }
public:
    vector <int> printBoundary(node *root)
    {
        vector<int> res;
        if (!root) return res;

        if (!isLeaf(root)) res.push_back(root->data);

        addLeftBoundary(root, res); 
        
        // add leaf nodes
        addLeaves(root, res);

        addRightBoundary(root, res); 
        return res;
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
    cout<<"\n Print Boundary => "<<endl;
    vector <int> ans=obj.printBoundary(root);
    for(auto x:ans){
        cout<<x<<" ";
    }
}