class Solution {
public:
  void DFS(vector<vector<int>>& graph, vector<bool> &visited,int v)
{
    visited[v] = true; //marking visited;
    
    //now check for its neighbors
    for(int i=0;i<graph[v].size();i++)
    {
        if(i == v)
            continue;
        
        if(graph[v][i] && !visited[i])
            DFS(graph,visited,i);
    }
    
}

int findCircleNum(vector<vector<int>>& graph) 
{
    int n = graph.size();
    
    vector<bool> visited(n,false);
    
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            DFS(graph,visited,i);
            ans++;
        }
    }
    return ans;
    }
};