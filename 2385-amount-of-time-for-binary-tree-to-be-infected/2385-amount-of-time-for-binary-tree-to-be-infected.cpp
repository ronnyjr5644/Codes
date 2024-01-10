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
    int amountOfTime(TreeNode* root, int start) {
		map<int,vector<int>>adj;
		queue<TreeNode*>q; q.push(root);
		// adjacency list formation
		while(!q.empty())
		{
			TreeNode*curr=q.front();
			q.pop();
			if(curr->left){
				q.push(curr->left);
				adj[curr->val].push_back(curr->left->val);
				adj[curr->left->val].push_back(curr->val);
			}
			if(curr->right){
				q.push(curr->right);
				adj[curr->val].push_back(curr->right->val);
				adj[curr->right->val].push_back(curr->val);
			}
		}
		// apply bfs 
		queue<int>q2;
		unordered_set<int>st;
		q2.push(start); st.insert(start);
		int level=0;
		while(!q2.empty())
		{
			int sz=q2.size();
			for(int i=0;i<sz;i++)
			{
				int curr=q2.front();
				q2.pop();
				for(auto &i:adj[curr])
				{
					if(st.count(i)==0)
					{
						q2.push(i);
						st.insert(i);
					}
				}
			}
			level++;
		}
		return level-1;
	}
};