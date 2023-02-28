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
     vector<TreeNode*>res;
        unordered_map<string,int>mp;
    string solve(TreeNode* root){
        if(!root){
            return "";
        }
        string x=solve(root->left);
        string y=solve(root->right);
        string l=to_string(root->val)+" "+x+" "+y;
        if(mp[l]==1){
            res.push_back(root);
        }
        mp[l]++;
        return l; 
        }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       
        solve(root);
        return res;
    }
};