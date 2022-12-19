class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
          vector<int>ans;
        if(n==1) return vector<int>{0};
     
        vector<int>d(n);     
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
            d[edges[i][0]]++;   
            d[edges[i][1]]++;
        }
            
        queue<int>q;
        for(int i=0;i<n;i++){
            if(d[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
           
            int size=q.size();
            for(int i=0;i<size;i++){
                int x=q.front();
                q.pop();
                d[x]--;
                if(n<=2){
                ans.push_back(x);
                }
                for(int& it:adj[x]){
                    d[it]--;
                    if(d[it]==1){
                        q.push(it);
                    }
                }
                
            }
            n-=size;
        }
        return ans;

    }
};