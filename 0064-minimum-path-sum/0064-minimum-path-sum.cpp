class Solution {
public:
    int dp[201][201];
     int fun(vector<vector<int>>& gr, int i, int j){
        if(i==gr.size()-1 && j==gr[0].size()-1){
            return gr[i][j];
        }
        if(i==gr.size() || j==gr[0].size()){
            return 1e8;
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = gr[i][j] + min(fun(gr,i+1,j), fun(gr,i,j+1));
    }
    int minPathSum(vector<vector<int>>& gr) {
        memset(dp,-1,sizeof(dp));
        return fun(gr,0,0);
    }
};