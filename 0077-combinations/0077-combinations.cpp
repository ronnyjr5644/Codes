class Solution {
public:
    void helper(vector<vector<int>> &res , vector<int>& ans , int n , int left , int k)
    {
     if(k == 0)
     {
         res.push_back(ans);
         return ;
     }
        
        for(int i = left ; i <= n ; i++)
        {
            ans.push_back(i);
            helper(res,ans,n,i+1,k-1);
            ans.pop_back();
        }
        
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> ans;
        
        helper(res,ans,n,1,k);
        
        return res;
    }
};