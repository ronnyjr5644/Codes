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
     void solve(TreeNode* root,vector<int>&n,int &cnt){
        if(root==NULL)
        return ;
        n[root->val]++;
        solve(root->left,n,cnt);
        solve(root->right,n,cnt);
        if(root->left==NULL && root->right==NULL){
            int flag=0;
            for(int i=1;i<=9;i++){
                if(n[i]%2!=0)
                flag++;
            }
            if( flag==1 || flag==0 )
                cnt++;
        }    
  n[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>n(10,0);
        int cnt=0;
        solve(root,n,cnt);
        return cnt;
    }
};