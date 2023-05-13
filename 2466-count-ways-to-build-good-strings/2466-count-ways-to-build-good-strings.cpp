class Solution {
public:
    int md = 1e9+7;
    
    int f(int ind, int l, int h, int z, int o, vector<long long>&dp){
        if(ind > h) return 0;
        if(dp[ind] != -1) return dp[ind];
        long long first = f(ind + z, l, h, z, o, dp) % md;  //zero
        long long sec = f(ind + o, l, h, z, o, dp) % md;  //one
        dp[ind] = (first+sec + (ind>=l && ind<=h)) % md;
        return dp[ind] ;
    }
    
    int countGoodStrings(int low, int high, int z, int o) {
        vector<long long>dp(high+1, -1);
        return f(0, low, high, z, o, dp); 
    }
};