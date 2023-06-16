class Solution {
public:
int mod=1e9+7;

    long solve(vector<int>& nums,vector<vector<long>> &dp) {

        if(nums.size()<=2) return 1;
        int root=nums[0];

        vector<int> toLeft;
        vector<int> toRight;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<root) toLeft.push_back(nums[i]);
            else toRight.push_back(nums[i]);
        }

        long leftWays=solve(toLeft,dp)%mod;
        long rightWays=solve(toRight,dp)%mod;
        long totalWays=(leftWays*rightWays)%mod;
        long comb=dp[nums.size()-1][toLeft.size()]%mod;
        return (totalWays*comb)%mod;

    }

    int numOfWays(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<long>> dp(n+1,vector<long>(n+1,0));
        dp[0][0]=1;

        for(int i=1;i<=n;i++){
            dp[i][0]=1;
            for(int j=1;j<=i;j++){
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
            }
        }

        long res=(solve(nums,dp)-1)%mod;
        int ans=res;
        return ans;

    }
};