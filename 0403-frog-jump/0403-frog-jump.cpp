class Solution {
public:
   vector<int>v;
    unordered_map<int,int> mp;
    bool f(vector<vector<int>> &dp,int i,int k){
        if(i==v.size()-1) return true;

        if(dp[i][k]!=-1) return dp[i][k];

        bool res=false;

        for(int j=-1;j<=1;j++){
            int nk = k+j;
            if(nk>0 && mp[v[i]+nk]){
                res|= f(dp,mp[v[i]+nk],nk);
            }
        }

        return dp[i][k]=res;
    }
    bool canCross(vector<int>& stones) {
        mp.clear();
        v=stones;
        vector<vector<int>> dp(stones.size(),vector<int>(50000,-1));
        for(int i=0;i<stones.size();i++){
            auto x = stones[i];
            mp[x]=i;
        }

           return f(dp,0,0);
}};