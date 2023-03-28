class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = *max_element(days.begin(), days.end());
        vector<int> dp(lastDay + 2, -1);
        dp[lastDay + 1] = 0;

        for (auto day : days) dp[day] = 0;
        for (int i = lastDay; i >= 0; i--) {
            // no trips that day, take the price of next day
            if (dp[i] == -1) dp[i] = dp[i + 1];
            else {
                dp[i] = dp[min(i + 1, lastDay + 1)] + costs[0]; // 1 day pass
                dp[i] = min(dp[i], dp[min(i + 7, lastDay + 1)] + costs[1]); // 7 day pass
                dp[i] = min(dp[i], dp[min(i + 30, lastDay + 1)] + costs[2]); // 30 day pass
            }
        }

        return dp[0];
    }
};