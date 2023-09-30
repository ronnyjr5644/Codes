class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int s3 = INT_MIN;
        stack<int> stk;
        for(int i = n- 1; i >= 0; i--){
            if(nums[i] < s3){
                return true;
            }else{
                while(!stk.empty() && nums[i] > stk.top()){
                    s3 = stk.top();
                    stk.pop();
                }
            }
            stk.push(nums[i]);
        }
        return false;

    }
};