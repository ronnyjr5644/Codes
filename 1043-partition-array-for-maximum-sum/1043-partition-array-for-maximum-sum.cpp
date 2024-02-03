class Solution {
int solve(vector<int>& arr, int n, int& k, vector<int>& dp) {
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int mx1 = INT_MIN, mx2 = INT_MIN;
        for(int i = n-1; i >= max(0, n-k); i--) {
            mx1 = max(mx1, arr[i]);
            mx2 = max(mx2, solve(arr, i, k, dp) + (n-i) * mx1);
        }
        return dp[n] = mx2;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return solve(arr, n, k, dp);
    }
};