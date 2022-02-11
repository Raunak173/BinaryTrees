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

void preDFS(node *root,vector <int> &pre){
    // root then left and then right
    if(root==NULL) return;
    pre.push_back(root->data);
    preDFS(root->left,pre);
    preDFS(root->right,pre);
}

void postDFS(node *root,vector <int> &post){
    // left then right and then root
    if(root==NULL) return;
    postDFS(root->left,post);
    postDFS(root->right,post);
    post.push_back(root->data);
}

void inDFS(node *root,vector <int> &in){
    // left then root and then right
    if(root==NULL) return;
    inDFS(root->left,in);
    in.push_back(root->data);
    inDFS(root->right,in);
}

vector <int> preorderTraversal(node *root){
    vector <int> pre;
    preDFS(root,pre);
    return pre;
}

vector <int> postorderTraversal(node *root){
    vector <int> post;
    postDFS(root,post);
    return post;
}

vector <int> inorderTraversal(node *root){
    vector <int> in;
    inDFS(root,in);
    return in;
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

int height(node *root){
    if(root==NULL) return 0;
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs)+1;
}

int Dheight(node* root, int &diameter) {
        if (!root) {
            return 0;
        }
        int lh = Dheight(root->left, diameter);
        int rh = Dheight(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
}

int diameterOfBinaryTree(node* root) {
        int diameter = 0;
        Dheight(root, diameter);
        return diameter;
}

int maxPathDown(node* node, int &maxi) {
        if (node == NULL) return 0;
        int left = max(0, maxPathDown(node->left, maxi));
        int right = max(0, maxPathDown(node->right, maxi));
        maxi = max(maxi, left + right + node->data);
        return max(left, right) + node->data;
}

int maxPathSum(node* root) {
       int maxi = INT_MIN; 
       maxPathDown(root, maxi); 
       return maxi;  
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

    cout<<"\n"<<"Preorder Traversal"<<endl;
    vector <int> pre = preorderTraversal(root);
    for(auto x:pre){
        cout<<x<<" ";
    }
    cout<<"\n"<<"Postorder Traversal"<<endl;
    vector <int> post = postorderTraversal(root);
    for(auto x:post){
        cout<<x<<" ";
    }
    cout<<"\n"<<"Inorder Traversal"<<endl;
    vector <int> in = inorderTraversal(root);
    for(auto x:in){
        cout<<x<<" ";
    }
    cout<<"\n"<<"Levelorder Traversal"<<endl;
    vector<vector<int>> level = levelOrder(root);
    for(auto x:level){
        for(auto y:x){
            cout<<y<<" ";
        }
    }
    cout<<"\n"<<"Height of tree = "<<height(root); 
    cout<<"\n"<<"Diameter of tree = "<<diameterOfBinaryTree(root); 
    cout<<"\n"<<"Max path sum = "<<maxPathSum(root); 
    return 0;
}