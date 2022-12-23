class Solution {
public:
   int dp[5002][2];
    int solve(vector<int>& prices, int idx, bool hold){
        if(idx>=prices.size()) return 0;
        if(dp[idx][hold]!=-1) return dp[idx][hold];
        
        if(!hold){
            int buy = solve(prices,idx+1,true)-prices[idx];
            int notbuy = solve(prices,idx+1,false);
            return dp[idx][hold] = max(buy,notbuy);
        }else{
             int sell = solve(prices,idx+2,false)+prices[idx];
             int notsell = solve(prices,idx+1,true);
            return dp[idx][hold] = max(sell,notsell);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,false);
    }
};