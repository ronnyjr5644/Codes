class Solution {
public:
    int solve(int node,const vector<vector<int>>&tree,const vector<bool>& hasApple, vector<bool>&vis){
        vis[node]=true;
        int depth=0;
        for(const auto & ch:tree[node]){
            if(vis[ch]==false){
                depth=depth+solve(ch,tree,hasApple,vis);
            }
        }
        return (depth || hasApple[node])?depth+1:0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>tree(n);
        vector<bool>vis(n);
        for(const auto &it:edges){
            tree[it[0]].push_back(it[1]);
            tree[it[1]].push_back(it[0]);
        }
        return max(0,2*(solve(0,tree,hasApple,vis)-1));
    }
};