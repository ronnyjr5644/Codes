class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         //im sir graphs alot
//         vector<vector<int>>adj(n);
//         for(int i=0;i<edges.size();i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
        
//         //chaliye bfs lagate hai
//         queue<int>q;
//         vector<int>vis(n,0);
//         //source dikh rha hai
//         q.push(source);
//         //dal dia queue me\
//         //nhi dalna tha
        
//         vis[source]=1;
//         //koi na ab visited ko 1 karna as we have traversed it
//         //chaliye traverse karte hai
//         while(!q.empty()){
//             auto top=q.front();
//             q.pop();
//             if(top==destination){
//                 return true;
//             }
//             for(auto it:adj[top]){
//                 if(vis[it]==0){
//                     q.push(it);
//                     vis[it]=1;
//                 }
//             }
            
//         }
//         return false;
        //chaliye shuru karte hai depth first search ka khel
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);
        return solve(adj,vis,source,destination);
    }
    bool solve(vector<vector<int>>&adj,vector<int>&vis,int curr,int end){
        if(curr==end){
            return true;
        }
        if(vis[curr]==1){
            return false;
        }
        vis[curr]=1;
        for(auto it:adj[curr]){
            if(solve(adj,vis,it,end)==1){
                return true;
            }
        
        }
        return false;
    }
};