class Solution {
public:
    void dfs(int headID, vector<int>& informTime, int ans, int& maxi, unordered_map<int, vector<int>>& adj){
		maxi=max(maxi, ans);
		for(auto it: adj[headID]){
			ans+=informTime[headID];
			dfs(it, informTime, ans, maxi, adj);
			ans-=informTime[headID];
		}
	}
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		unordered_map<int, vector<int>>adj;
		int ans=0, maxi=0;
		for(int i=0; i<manager.size(); i++){
			if(manager[i]!=-1){
				adj[manager[i]].push_back(i);
			}
		}
		dfs(headID, informTime, ans, maxi, adj);
		return maxi;
	}
};