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

class Solution{
    public:
    vector<int> topView(node *root){
    
    vector <int> v;
    /* map to store node at each vertical(horizontal) distance(Level)
    i.e. stores top view */
    map<int,int> Map;
    queue<pair<node*,int>> q;
    
    q.push({root,0});
    
    // obtain top view of binary tree into the Map
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        
        node *curr = top.first;
        int horizontalLevel = top.second;
        
        /* if the current horizontal Level has not been
        visited then the first node encountered at this horizontal 
        level during level order traversal should be displayed 
        in top view of the tree */
        if(Map.find(horizontalLevel) == Map.end())
        Map[horizontalLevel] = curr->data;
        
        if(curr->left)
        q.push({curr->left,horizontalLevel-1});
        
        if(curr->right)
        q.push({curr->right,horizontalLevel+1});
    }
    
    // print the top view in order of horizontal Level
    for(auto i : Map)
    v.push_back(i.second);
    
    return v;
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
    cout<<"\n Top View => "<<endl;
    vector <int> ans=obj.topView(root);
    for(auto x:ans){
        cout<<x<<" ";
    }
}