class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
          int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for(int ind = 1; ind <= n; ind++){
            for(int pick = 0; pick <= k; pick++){
                int res = 0;
                int sum = 0;
                for(int i = 0; i <= piles[ind - 1].size() && i <= pick; i++){
                    if(i > 0) sum += piles[ind - 1][i - 1];
                    res = max(res, sum + dp[ind - 1][pick - i]);
                }
                dp[ind][pick] = res;
            }
        }
        return dp[n][k];
    }
};