class Solution {
public:
       int func(int steps,int arrlen,int n)
    {
        if(steps==0)
        {
            if(arrlen==0)
                return 1;
            return 0;
        }
        int left=0;
        if(arrlen-1>=0)
            left=func(steps-1,arrlen-1,n);
        int same=func(steps-1,arrlen,n);
        int right=0;
        if(arrlen+1<n) 
            right=func(steps-1,arrlen+1,n);
        return left+same+right;
    }
    int numWays(int steps, int arrLen) {

        int mod=1e9+7;
        int n=min(arrLen,steps);
        vector<vector<int>> dp(steps+1,vector<int>(n+1,0));

        dp[0][0]=1;
        for(int ste=1;ste<=steps;ste++)
        {
            for(int len=n-1;len>=0;len--)
            {
                long long left=0;
                if(len-1>=0)
                    left=dp[ste-1][len-1]%mod;

                long long same=dp[ste-1][len]%mod;

                long long right=0;
                if(len+1<n) 
                    right=dp[ste-1][len+1]%mod;

                dp[ste][len]=(int)((left+same+right)%mod);
            }
        }
        return dp[steps][0];
        // return func(steps,0,n);
    }
};