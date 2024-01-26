class Solution {
public:
      const int mod=1e9+7;
    int helper(int m,int n,int maxm,int i,int j,vector<vector<vector<int> > > &dp)
    {
        if(i>=m || j>=n || i<0 || j<0)
        {
            return 1;
        }
        if(maxm<=0)
        {
            return 0;
        }
        if(dp[i][j][maxm]!=-1)
        {
            return dp[i][j][maxm];
        }
        int ways=0;
        ways=(ways + helper(m,n,maxm-1,i-1,j,dp))%mod;
        ways=(ways + helper(m,n,maxm-1,i+1,j,dp))%mod;
        ways=(ways + helper(m,n,maxm-1,i,j-1,dp))%mod;
        ways=(ways + helper(m,n,maxm-1,i,j+1,dp))%mod;
        return dp[i][j][maxm]=ways%mod;
    }
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        vector<vector<vector<int> > > dp(m, vector<vector<int> >(n, vector<int>(maxMove+1,-1)));
        return helper(m,n,maxMove,sr,sc,dp);
    }
};