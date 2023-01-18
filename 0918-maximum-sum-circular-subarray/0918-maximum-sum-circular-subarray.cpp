class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
         int mini = 0;
        int maxi = INT_MIN;
        int sum = 0;
        int t1=0;
        int t2=0;
        for(int i = 0 ; i<nums.size();i++){
            sum+=nums[i];
            t1 = min(nums[i]+t1,nums[i]);
            mini = min(t1,mini);
            t2 = max(nums[i]+t2,nums[i]);
            maxi = max(t2,maxi);
        }
        if(sum==mini){
             return maxi;
        }
        return max(maxi,sum-mini);
    }
};