class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
         int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        int k = 0;

        for(int i=0; i<m; i++){
            k += int(s1[i]);
        }
        for(int i=0; i<n; i++){
            k += int(s2[i]);
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 2 * int(s1[i-1]) + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return k - dp[m][n];
    }
};