//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        if (r>n) return 0;
        vector<vector<int>> dp(r+1,vector<int>(n+1, -1));
        function<int(int,int)> x = [&](int n, int r) {
            if(r==0||r==n)return 1;
            if(r>n)return 0;
            if(dp[r][n]!=-1)return dp[r][n];
            return dp[r][n]=(x(n-1,r-1)+x(n-1,r))%1000000007;
        };
        return x(n,r);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends