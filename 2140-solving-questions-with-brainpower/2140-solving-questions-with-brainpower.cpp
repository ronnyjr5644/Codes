class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
              int n=questions.size();
        long long ans=0;
        vector<pair<long long,long long>> dp(n);
        for(int i=n-1;i>=0;i--){
            int x=i+questions[i][1]+1;
            if(x<n) dp[i].first= questions[i][0] + max(dp[x].first,dp[x].second); 
            else dp[i].first=questions[i][0];
            ans=max(ans,dp[i].first);
            dp[i].second=ans;
        }
        return ans;
    }
};