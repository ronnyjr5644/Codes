class Solution {
public:
    int tribonacci(int n) {
        int temp=0;
        vector<int>dp = {0, 1, 1};
        for (int i = 3; i <= n; ++i){
            temp=dp[i-3]+dp[i-2]+dp[i-1];
            dp.push_back(temp);
        }
    return dp[n];
    }
};

        