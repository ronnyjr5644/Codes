class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int cur_sum = 0;
        int max_sum = INT_MIN;
  for (int x : nums) {
    cur_sum += x;
    max_sum = max(max_sum, cur_sum);
    if (cur_sum < 0) {
      cur_sum = 0;
    }
  }
  return max_sum;
    }
};