//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int dp[301][301];
    int solve(int i,int j,vector<int>&arr){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int res=INT_MIN;
        for(int k=i;k<=j;k++){
            int cost=arr[i-1]*arr[k]*arr[j+1]+solve(i,k-1,arr)+solve(k+1,j,arr);
            res=max(res,cost);
        }
        return dp[i][j]=res;
    }
    int maxCoins(int N, vector<int> &arr) {
        memset(dp,-1,sizeof(dp));
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        return solve(1,N,arr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends