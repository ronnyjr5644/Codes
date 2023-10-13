class Solution {
public:
//    int solve(vector<int>& cost,int i,int n,vector<int>&dp){
// if(i>=n)return 0;
// if(i==n-1)return cost[n-1];
// if(dp[i]!=-1)return dp[i];
// int onejump = cost[i]+solve(cost,i+1,n,dp);
// int twojump = cost[i]+solve(cost,i+2,n,dp);
// return dp[i] = min(onejump,twojump);

// }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int>dp(n+1,-1);
//         return min(solve(cost,0,n,dp),solve(cost,1,n,dp));
//     }
        int minCostClimbingStairs(vector<int>& cost) {
      int n=cost.size();
            for(int i=2;i<n;i++){
                cost[i]=min(cost[i-1],cost[i-2])+cost[i];
            }
            return min(cost[n-2],cost[n-1]);
    }
};