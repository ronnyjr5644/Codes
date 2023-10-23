//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     bool isPall(string s, int low, int high)
    {
        while(low <= high)
        {
            if(s[low++] != s[high--])
            return 0;
        }
        return 1;
    }
    int dp[501];
    int solve(int i, string &s)
    {
        if(i >= s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int ans = INT_MAX;
        for(int j = i; j < s.size(); j++)
        {
            if(isPall(s, i, j))
            ans = min(ans, 1 + solve(j + 1, s));
        }
        return dp[i] = ans;
    }
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, str) - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends