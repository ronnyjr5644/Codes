//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
       vector<vector<pair<int,int>>>adj(n+1);
       vector<int>dist(n+1,INT_MAX);
       for(int i=0;i<flights.size();i++){
           adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
       }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       dist[k]=0;
       pq.push({dist[k],k});
       while(!pq.empty()){
           auto it=pq.top();
           pq.pop();
           int node=it.second;
           int distance=it.first;
           for(auto child:adj[node]){
               if(dist[child.first]>(distance+child.second)){
                   dist[child.first]=(distance+child.second);
                   pq.push({dist[child.first],child.first});
               }
           }
       }
       int ans=-1;
       for(int i=1;i<=n;i++){
           if(dist[i]==INT_MAX){
               return -1;
           }
           else{
               ans=max(ans,dist[i]);
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends