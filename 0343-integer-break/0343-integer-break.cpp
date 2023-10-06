class Solution {
public:
    int dp[59];
    int solve(int &n){
       if( n==1 || n==0){
            return 1;
       }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        for(int i=1;i<n;i++){
            int x=n-i;
            int take=i*solve(x);
            int take2=i*x;
            ans=max({ans,take,take2});
        }
        return dp[n]=ans;
    
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};