/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* rec(int *in, int left, int right, int *post, int &i, map<int, int> &idx)
{
    if (i < 0 || left >= right)
        return NULL;
        
    int mid = idx[post[i --]];
    Node *root = new Node(in[mid]);
    root->right = rec(in, mid + 1, right, post, i, idx);
    root->left  = rec(in, left   , mid  , post, i, idx);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    int i = n - 1;
    map<int, int> idx;
    
    for(int i = 0; i < n; ++i)
        idx[in[i]] = i;
    
    return rec(in, 0, n, post, i, idx);
}
