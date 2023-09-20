class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
         int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        if(sum < x) return -1;
        sum -= x;
        int temp = 0, l = 0, r = 0;
        int maxi = -1;
        while(r < nums.size()){
            temp += nums[r];
            while(temp > sum){
                temp -= nums[l];
                l++;
            }
            if(temp == sum){
                maxi = max(maxi, r - l + 1);
            }
            r++;
        }
        
        return maxi == -1? -1 : nums.size() - maxi;
    }
};