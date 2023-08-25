class Solution {
public:
      int dp[101][101];
    bool solve(int i,int j,int k,string &s1, string &s2, string &s3){
        if(i==s1.size() && j==s2.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=false;
        if(i<s1.size() && s1[i]==s3[k]) ans |= solve(i+1,j,k+1,s1,s2,s3);
        if(j<s2.size() && s2[j]==s3[k]) ans |= solve(i,j+1,k+1,s1,s2,s3);
        return dp[i][j]=ans;

    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,s1,s2,s3);
    }
};