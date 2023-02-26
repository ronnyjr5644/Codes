class Solution {
public:
    int dp[501][501];
    int solve(string word1,string word2,int n1,int n2){
        if(n1==0){
            return n2;
        }
        if(n2==0){
            return n1;
        }
        if(dp[n1][n2]!=-1){
            return dp[n1][n2];
        }
        if(word1[n1-1]==word2[n2-1]){
            return dp[n1][n2]=solve(word1,word2,n1-1,n2-1);
            
        }
        return dp[n1][n2]= 1+min({solve(word1,word2,n1,n2-1),solve(word1,word2,n1-1,n2),solve(word1,word2,n1-1,n2-1)});
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof((dp)));
        int n1=word1.size();
        int n2=word2.size();
        return solve(word1,word2,n1,n2);
    }
};