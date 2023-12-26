class Solution {
public:
     const int mod=1e9+7;
    
    int recursion(int N, int& K, int Target, vector<vector<int>>&dp){
        if(Target==0 and N==0){
            return dp[N][Target]=1;  
        }
        if(Target==0 and N!=0){
            return dp[N][Target]=0;
        }
        if(Target!=0 and N==0){
            return dp[N][Target]=0;
        }
        if(dp[N][Target]!=-1){
            return dp[N][Target];
        }
        dp[N][Target]=0;
        
      // for(int i=1;i<=K;i++){
      //     if(i<=Target){
      //         dp[N][Target]=((dp[N][Target]%mod)+(recursion(N-1,K,Target-i),dp))%mod;
      //     }
      // }
        for(int i=1;i<=K;i++){
            if(i<=Target){
                dp[N][Target]=( (dp[N][Target]%mod) + (recursion(N-1,K,Target-i,dp)%mod) )%mod;
            }
        }
        
        return dp[N][Target]%mod;   
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return recursion(n,k,target,dp);
    }
};