class Solution {
public:
    bool dfs(vector<vector<int>> &graph, int node, vector<int> &state)
    {
        if(state[node] == 1)
            return false;
        if(state[node] == 2)
            return true;
        state[node] = 1;
        for(auto it : graph[node])
            if(!dfs(graph,it,state))
                return false;
        state[node] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> state(n,0);          
        for(int i=0;i<n;i++)
            if(dfs(graph,i,state))
                ans.push_back(i);
        return ans;
    }
};