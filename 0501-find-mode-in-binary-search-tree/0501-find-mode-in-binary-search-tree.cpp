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
   void solve(TreeNode* root, unordered_map<int, int> &mp, int &max){
        if(root == NULL) return ;
        solve(root -> left, mp, max);
        solve(root -> right, mp, max);
        mp[root -> val]++;
        if(mp[root->val] > max) max = mp[root -> val];
    }
    vector<int> findMode(TreeNode* root) {
        int max = 0;
        unordered_map<int, int> mp;
        vector<int> ans;
        solve(root, mp, max);
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            if(it->second == max) {
                ans.push_back(it->first); 
            }
        }
        return ans;
    }
};