class Solution {
public:
int solve(vector<int>& cost, vector<int>& time,int i,int remWall,vector<vector<int>>& dp){
    //base case
     if(remWall <= 0){
        return 0;
    }
    if (i >= cost.size()) {
            return 1e9;
        }
    if(dp[i][remWall] !=-1){
        return dp[i][remWall];
    }
   
    int notpaid =0+solve(cost,time,i+1,remWall,dp);
    int paid =cost[i]+solve(cost,time,i+1,remWall-time[i]-1,dp);
    int ans=min(paid,notpaid);
    dp[i][remWall] =ans;
    return ans;
    
}
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int i=0;
        int remWall=cost.size();
        vector<vector<int>> dp(cost.size()+1,vector<int>(cost.size()+1,-1));
        int ans= solve(cost,time,i,remWall,dp);
        return ans;
    }
};