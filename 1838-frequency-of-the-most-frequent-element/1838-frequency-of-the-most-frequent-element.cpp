class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        long long left=0,right=0;
        long long total=0,maxlen=0;
        while(right<n){
            total += nums[right];
            if(nums[right]*(right-left+1)-total <= k){
                maxlen = max(maxlen,right-left+1);
            }
            else{
                total -= nums[left];
                left++;
            }
            right++;
        }
        return maxlen;
    }
};