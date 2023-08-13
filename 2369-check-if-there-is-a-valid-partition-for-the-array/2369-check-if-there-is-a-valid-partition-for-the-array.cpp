class Solution {
public:
   bool solve(int n,vector<int>& nums,vector<int> &dp)
    {
        if(n<0) return 1;
        if(dp[n]!=-1) return dp[n];
        bool a=0,b=0,c=0;
        if(n-1>=0 && nums[n]==nums[n-1]) a=solve(n-2,nums,dp);
         if(n-2>=0 && nums[n]==nums[n-1] && nums[n-1]==nums[n-2]) b=solve(n-3,nums,dp);
          if(n-2>=0 && nums[n]==nums[n-1]+1 && nums[n-1]==nums[n-2]+1) c=solve(n-3,nums,dp);
          return dp[n]=a|b|c;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(n-1,nums,dp);
    }
};