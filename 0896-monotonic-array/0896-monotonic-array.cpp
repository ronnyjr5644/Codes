class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
          int direction = 0;
        for(int i = 1; i < nums.size(); i++){
            if(direction > 0 && nums[i] < nums[i-1]) return false;
            if(direction < 0 && nums[i] > nums[i-1]) return false;
            if(direction == 0) direction = nums[i] - nums[i-1];
        }
        return true;
    }
};