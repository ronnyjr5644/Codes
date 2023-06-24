class Solution {
public:
   int build_board(vector<int> &rods, int balance,int i,vector<vector<int>> &memo)
    {
        if(i>=rods.size() && balance==0)
            return 0;
        if(i>=rods.size() && balance!=0)
            return INT_MIN;

        if(memo[i][balance+5000]!=-1)
            return memo[i][balance+5000];
        int left= build_board(rods,balance+rods[i],i+1,memo);
        int right= build_board(rods,balance-rods[i],i+1,memo);

        int ans= rods[i]+max(left,right);

        int skip= build_board(rods,balance,i+1,memo);

        ans= max(ans,skip);

        memo[i][balance+5000]=ans;
        return ans;

    }

    int tallestBillboard(vector<int>& rods) {
        
        vector<vector<int>> memo(rods.size(),vector<int>(10001,-1));
        int ans= build_board(rods,0,0,memo);

        if(ans<=0)
            return 0;
        else
            return ans/2;
    }
};