class Solution {
public:
       vector<vector<int>>dp;
    int memo(int amount,int ind,vector<int>&coins){
        if(amount == 0)return 1;
        if(ind < 0 || amount < 0)return 0;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        int pick = memo(amount - coins[ind],ind,coins);
        int notpick = memo(amount,ind-1,coins);

        return dp[ind][amount] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));
        return memo(amount,n-1,coins);
    }
};