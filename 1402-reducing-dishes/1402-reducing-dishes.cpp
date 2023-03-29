class Solution {
public:
    int dp[501][501];
   int solve(vector<int>&sat , int index , int time){
    int n=sat.size();
    if(index==n) return 0;
    if(dp[index][time]!=-1){
        return dp[index][time];
    }
    return dp[index][time]=max(sat[index]*(time+1) + solve(sat , index+1 , time+1) , solve(sat , index+1 , time));
}
int maxSatisfaction(vector<int>& sat) {
    sort(sat.begin() , sat.end());
    memset(dp,-1,sizeof(dp));
    return solve(sat , 0 , 0);
}
};