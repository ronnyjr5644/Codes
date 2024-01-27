class Solution {
public:
    int modulo = 1e9+7;
    int solve(int n, int k, vector<vector<int>>& dp) {
        if (k == 0) return 1;
        if (n == 0) return 0;
        
        if(dp[n][k]!=-1) return dp[n][k];

        int count=0;
        for (int i=0; i<=min(n-1, k); ++i) {
            count = ((count) + solve(n-1, k-i, dp));
            count %= modulo;
        }
        return dp[n][k] = count;
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(1001 , vector<int>(1001, -1));
        return solve(n, k, dp);
    }
};