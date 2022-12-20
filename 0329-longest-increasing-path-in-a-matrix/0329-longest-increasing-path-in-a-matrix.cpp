class Solution {
public:
    int dp[201][201];
    int dfs(vector<vector<int>>& mat,int i,int j,int x){
        if(i<0 || j<0 || i==mat.size() || j==mat[0].size()|| x>=mat[i][j]){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=max({dfs(mat,i+1,j,mat[i][j]),dfs(mat,i-1,j,mat[i][j]),dfs(mat,i,j+1,mat[i][j]),dfs(mat,i,j-1,mat[i][j])})+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int res=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                res=max(dfs(matrix,i,j,-1),res);     
            }
        }
        return res;
    }
};