class Solution {

    vector<vector<int>>res;
    private:
    void solve(int node,vector<vector<int>>&graph,vector<int>&temp){
        temp.push_back(node);
        if(node==graph.size()-1){
            res.push_back(temp);
        }
        for(auto it:graph[node]){
            solve(it,graph,temp);
        }
        temp.pop_back();
    }
    public:
    	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            for(int i=0;i<graph[0].size();i++){
                vector<int>temp;
                temp.push_back(0);
                solve(graph[0][i],graph,temp);
            }
            return res;
    }
};