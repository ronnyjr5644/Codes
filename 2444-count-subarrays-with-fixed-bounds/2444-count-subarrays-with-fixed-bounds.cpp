class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size(), low=-1, high=-1, l=0;
        long long count = 0;
        
        for(int i=0; i<n; i++) {
            if(nums[i]>=minK and nums[i]<=maxK) {
                if(nums[i] == minK) low = i;
                if(nums[i] == maxK) high = i;
                
                if(low!=-1 and high!=-1) count += min(low, high) - l + 1;
            }
            else {
                l = i+1;
                low = -1;
                high = -1;
            }
        }
        
        return count; 
    }
};