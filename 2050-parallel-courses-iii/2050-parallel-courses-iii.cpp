class Solution {
public:
    int memoizationDfs(int course, vector<vector<int>>& graph, vector<int>& time, vector<int>& dp) {
        if (dp[course] != -1) return dp[course];
        int maxTime = 0;
        for (int nextCourse : graph[course]) {
            maxTime = max(maxTime, memoizationDfs(nextCourse, graph, time, dp));
        }
        dp[course] = maxTime + time[course - 1];
        return dp[course];
    }
    
   int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n + 1);
        for (const auto& relation : relations) {
            int prevCourse = relation[0];
            int nextCourse = relation[1];
            graph[prevCourse].push_back(nextCourse);
        }
        vector<int> dp(n + 1, -1);
        int minTime = 0;
        for (int i = 1; i <= n; i++) {
            minTime = max(minTime, memoizationDfs(i, graph, time, dp));
        }
        return minTime;
    }

    
};