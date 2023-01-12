class Solution {
public:
       void getCount(int i, vector<vector<int>>&adj, string& labels, vector<int>& counts, vector<int>& res) {
        int count=counts[labels[i] - 'a'];
        res[i]=0;
        for(int node:adj[i]) {
            if(res[node] == -1){
                getCount(node,adj,labels,counts,res);
            }
        }
        counts[labels[i] - 'a']=counts[labels[i] - 'a']+1;
        res[i] =counts[labels[i] - 'a']-count;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> counts(26, 0);
        vector<int> res(n, -1);
        vector<vector<int>>adj(n);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        getCount(0,adj,labels,counts,res);
        return res;
    }
};