//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    void solve(int i,int j,vector<vector<int>>& mat,vector<vector<int>> &vis,int prev){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || vis[i][j]==1 || prev>mat[i][j]){
            return;
        }
        vis[i][j]=1;
        solve(i,j+1,mat,vis,mat[i][j]);    
        solve(i,j-1,mat,vis,mat[i][j]);   
        solve(i+1,j,mat,vis,mat[i][j]);  
        solve(i-1,j,mat,vis,mat[i][j]); 
        return;
    }
    int water_flow(vector<vector<int>> &mat,int N,int M){
        vector<vector<int>>visI(N,vector<int>(M,0));
        vector<vector<int>>visA(N,vector<int>(M,0));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                 if((j==M-1 || i==N-1) && !visA[i][j]) {
                     solve(i,j,mat,visA,-1);
                }
                 if((j==0 || i==0) && !visI[i][j]){
                    solve(i,j,mat,visI,-1);
                }
            }
        }
        int count=0;
        for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visI[i][j]==1 && visA[i][j]==1){
                count++;
            }
        }
    }
    return count;
        
    
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends