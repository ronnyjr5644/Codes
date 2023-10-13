//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    void solve(Node* root,priority_queue<int>&pq){
        if(root==nullptr){
            return;
        }
        solve(root->left,pq);
        pq.push(root->data);
        solve(root->right,pq);
    }
    int floor(Node* root, int x) {
        
        priority_queue<int>pq;
        solve(root,pq);
        while(!pq.empty()){
            if(pq.top()>x){
                pq.pop();
            }
            else{
                return pq.top();
            }
        }
 
        return -1;
        
        
    }
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends