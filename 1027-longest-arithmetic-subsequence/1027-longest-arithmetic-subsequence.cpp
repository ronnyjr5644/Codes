class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
         int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(1001, 1));

        int res = 1, diff;

        for(int ind = 0; ind < n; ind++){
            for(int prev = 0; prev < ind; prev++){
                diff = nums[ind] - nums[prev];
                dp[ind][diff + 500] = max(dp[ind][diff + 500], 1 + dp[prev][diff + 500]);
                res = max(res , dp[ind][diff + 500]);
            }
        }
        return res;
    }
};