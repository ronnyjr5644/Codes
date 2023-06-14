/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     void inOrder(TreeNode *root,vector<int> &BST) { 
        if(!root) return; 
        inOrder(root->left,BST); 
        BST.push_back(root->val); 
        inOrder(root->right,BST);    
    }
    int getMinimumDifference(TreeNode* root) { 
        int minDiff = INT_MAX;  
        vector<int> BST; 
        inOrder(root,BST);
        for(int i = 0; i < BST.size()-1; i++) 
            minDiff = min(BST[i+1] - BST[i],minDiff);
        return minDiff;
    }
};