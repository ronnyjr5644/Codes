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
      TreeNode* solve(vector<int>&inorder, vector<int>&postorder, int istart, int iend,
                  int pstart,int pend){
        if(istart > iend || pstart > pend)
            return NULL;
        int val = postorder[pend];
        
        int i = istart;
        while(inorder[i] != val) i++;

        TreeNode* root = new TreeNode(val);
        root->left = solve(inorder, postorder, istart, i-1, pstart, pstart+i-istart-1);
        root->right = solve(inorder, postorder, i+1, iend, pend-(iend-i), pend-1);
        return root;
    }
   TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    
  
};