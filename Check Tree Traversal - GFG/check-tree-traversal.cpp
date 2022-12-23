//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    struct Node{
        int data;
        struct Node *left;
        struct Node *right;
        Node(int x){
            data=x;
            left=NULL;
            right=NULL;
        }
    };
    Node* constructTree(int pre[],int in[],unordered_map<int,int>&mp,int N,int start,int end,int &index){
        if(start>end || index>N){
            return NULL;
        }
        int currIndex=mp[pre[index]];
        Node *root=new Node(pre[index++]);
        root->left=constructTree(pre,in,mp,N,start,currIndex-1,index);
        root->right=constructTree(pre,in,mp,N,currIndex+1,end,index);
        return root;
    }
    void postOrder(Node *root,vector<int>&post){
         if(root==NULL) return ;
        postOrder( root->left,post);
        postOrder(root->right,post);
        post.push_back(root->data);
    }
     bool checktree(int preorder[], int inorder[], int postorder[], int N){ 
     unordered_map<int,int>mp;
     for(int i=0; i<N;i++){
         mp[inorder[i]]=i;
     }
     int index=0;
     Node *root=constructTree(preorder,inorder,mp,N,0,N-1,index);
     vector<int>post;
     postOrder(root,post);
     for(int i=0;i<N;i++){
         if(post[i]!=postorder[i]){
             return false;
         }
     }
     return true;
    } 
};


//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 


// } Driver Code Ends