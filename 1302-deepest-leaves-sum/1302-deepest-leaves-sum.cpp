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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int nodes= 1;
        int ans = root->val;
        while(!q.empty()){
            int n=nodes;
            nodes = 0;
            ans = 0;
            for(int i=0;i<n;i++){
                TreeNode* x= q.front();
                q.pop();
                ans +=x->val;
                if(x->left != NULL){
                    q.push(x->left);
                    nodes++;
                }
                if(x->right != NULL){
                    q.push(x->right);
                    nodes++;
                } 
            } 
        }
        return ans;
    }
};