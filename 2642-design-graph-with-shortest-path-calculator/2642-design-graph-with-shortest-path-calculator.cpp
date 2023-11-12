class Graph {

      int n;
    vector<vector<vector<int>>> e;
public:
    Graph(int n_, vector<vector<int>>& edges) : n(n_) {
       e.resize(n);
       for(auto &edge : edges) addEdge(edge);
        
    }
    
    void addEdge(vector<int> edge) {
        e[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> visited(n,INT_MAX);
        queue<int> q;
        q.push(node1);
        visited[node1]=0;
        while(!q.empty())
        {
            int node = q.front();
            int cost = visited[node];
            q.pop();
            for (auto &edge : e[node])
            {
                if (cost + edge[1] >= visited[edge[0]]) continue;
                if (cost + edge[1] >= visited[node2]) continue;
               visited[edge[0]] =  cost + edge[1];
               q.push(edge[0]);
            }
        }
        if (visited[node2] == INT_MAX) return -1;
        return visited[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */