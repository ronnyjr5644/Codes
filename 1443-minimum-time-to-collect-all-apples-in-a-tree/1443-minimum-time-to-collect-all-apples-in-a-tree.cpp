class Solution {
public:
    int solve(int node,vector<vector<int>>&adj,vector<bool>& hasApple, vector<bool>&vis){
        vis[node]=true;
        int depth=0;
        for(auto ch:adj[node]){
            if(vis[ch]==false){
                depth=depth+solve(ch,adj,hasApple,vis);
            }
        }
        return (depth || hasApple[node])?depth+1:0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        vector<bool>vis(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return max(0,2*(solve(0,adj,hasApple,vis)-1));
    }
};