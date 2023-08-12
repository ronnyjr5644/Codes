class Solution {
public:
     int n, m;
    int dp[101][101];
    long long numsPaths(int i, int j, vector<vector<int>>& obstacleGrid)
    {       
        if (dp[i][j]!=-1) return dp[i][j];
        if (obstacleGrid[i][j]==1) return dp[i][j]=0;
        long long ans=0;
        if (i>0) ans+=numsPaths(i-1, j, obstacleGrid);
        if (j>0) ans+=numsPaths(i, j-1, obstacleGrid);
        if (i==0 && j==0) ans=(obstacleGrid[0][0]==0)?1:0;
        return dp[i][j]=ans;     
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n=obstacleGrid.size();
        m=obstacleGrid[0].size();
        memset(dp,-1,sizeof(dp));

        return numsPaths(n-1, m-1, obstacleGrid);
    }
};