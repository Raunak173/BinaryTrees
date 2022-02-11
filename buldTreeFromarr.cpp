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

node *buildTree(int arr[],int s,int e){
    if(s>e) return NULL;
    int mid=(s+e)/2;
    node *root = new node(arr[mid]);
    root->left=buildTree(arr,s,mid-1);
    root->right=buildTree(arr,mid+1,e);
    return root;
}

vector<vector<int>> levelOrder(node* root) {
        vector<vector<int>> ans; 
        if(root == NULL) return ans; 
        queue<node*> q; 
        q.push(root); 
        while(!q.empty()) {
            int size = q.size();
            vector<int> level; 
            for(int i = 0;i<size;i++) {
                node *p = q.front(); 
                q.pop(); 
                if(p->left != NULL) q.push(p->left); 
                if(p->right != NULL) q.push(p->right); 
                level.push_back(p->data); 
            }
            ans.push_back(level); 
        }
        return ans; 
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    node *root = buildTree(arr,0,n-1);
    vector<vector<int>>ans = levelOrder(root);
    for(auto v:ans){
        for(auto x:v){
            cout<<x<<" ";
        }
    }
    return 0;
}