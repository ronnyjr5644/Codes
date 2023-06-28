class Solution {
public:
  void djikstraPath(vector<pair<int, double>> adj[], int totalNodes, int source, vector<double> &dist) {
        priority_queue<pair<double, int>,vector <pair<double, int>>> pq;
        pq.push(make_pair(1, source));
        dist[source] = 1;
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for(int v = 0; v < adj[u].size(); ++v) {
                int neighbour= adj[u][v].first;
                double weight = adj[u][v].second;
                if(dist[neighbour] < dist[u] * weight) {
                    dist[neighbour] = dist[u] * weight;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        vector<double> dist(n, 0);
        int i;
        for(i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        djikstraPath(adj, n, start, dist);
        return dist[end];
    }
};