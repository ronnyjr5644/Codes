class Solution {
public:
int ans = -1;
void dfs(vector<vector<int>> &graph, vector<int> &v, int crt, int dd, map<int,int> &mp){
    v[crt] = 1;
    mp[crt] = dd;
    for(auto x:graph[crt]){
        if(!v[x])dfs(graph, v, x, dd+1, mp);
        else if(mp.count(x)) ans = max(ans, dd-mp[x]+1);
    }
}

int longestCycle(vector<int>& e) {
    vector<vector<int>> graph(e.size());
    for(int i = 0; i<e.size(); i++){
        if(e[i]!=-1){
            graph[i].push_back(e[i]);
        }
    }
    vector<int> visited(e.size(),0);
    for(int i = 0; i<e.size(); i++){
        if(!visited[i]){
            map<int,int> mp;
            dfs(graph, visited, i, 0, mp);
        }
    }
    return ans;
	}
};