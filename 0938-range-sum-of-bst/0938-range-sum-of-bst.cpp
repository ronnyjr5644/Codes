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
       void dfs(TreeNode* root, int L, int R, int& sumOfRange){
        if(!root) return;
        if(root->val >= L && root->val <= R) sumOfRange += root->val;
        if(root->val > L) dfs(root->left, L, R, sumOfRange);
        if(root->val < R) dfs(root->right, L, R, sumOfRange);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sumOfRange = 0;
        dfs(root, low, high, sumOfRange);
        return sumOfRange;
    }
};