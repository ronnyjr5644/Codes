class Solution {
public:
     int dp[1001][1001];
     int solve(vector<vector<int>>&arr,int i,int n,int maxiAge){
        if(i==n){
            return 0;
        }
        if(dp[i][maxiAge]!=-1){
            return dp[i][maxiAge];
        }
        if(arr[i][1]>=maxiAge){
            return dp[i][maxiAge]=max(arr[i][0]+solve(arr,i+1,n,arr[i][1]),solve(arr,i+1,n,maxiAge));
        }
        return dp[i][maxiAge]=solve(arr,i+1,n,maxiAge);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages){
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>arr;
        for(int i=0;i<scores.size();i++){
            arr.push_back({scores[i],ages[i]});
        }
        sort(arr.begin(),arr.end());     
        return solve(arr,0,ages.size(),0);
    }
};