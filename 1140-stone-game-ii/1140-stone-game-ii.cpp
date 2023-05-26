class Solution {
public:
   int dp[101][1001];
    int solve(vector<int>& piles,int ind, int m){
        if(ind>=piles.size()){
            return 0;
        }
        if(dp[ind][m]!=-1){
            return dp[ind][m];
        }
        int sum = 0;
        if(ind+2*m>=piles.size()){
            for(int i=ind;i<piles.size();i++){
                sum+=piles[i];     
            }
            return dp[ind][m] = sum;
        }
        
        int value = INT_MIN;
        
        for(int i=1;i<=m*2;i++){
            sum+=piles[ind+i-1];
            value = max(value,sum-solve(piles,ind+i,max(m,i)));
        }
        return dp[ind][m] = value;
    }
    
    
    int stoneGameII(vector<int>& piles) {
        int m = 1;
        memset(dp,-1,sizeof(dp));
        int value = solve(piles,0,m);
        
        
        
        int total_stones = 0;
        for(int i=0;i<piles.size();i++){
            total_stones+= piles[i];
        }
        int profit_alice = (total_stones+value)/2;
        return profit_alice;
        
    }
};