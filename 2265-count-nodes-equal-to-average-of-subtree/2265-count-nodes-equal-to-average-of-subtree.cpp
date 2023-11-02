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
     int ans = 0;
    int average(TreeNode * root, int &cnt)
    {
        if(!root) return 0;
        cnt++;
        return root->val + average(root->left, cnt) + average(root->right, cnt);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        int cnt = 0;
        int sum = average(root, cnt);
        if(sum/cnt == root->val)
        {
            ans++;
        }
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);

        return ans;
    }
};