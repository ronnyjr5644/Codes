class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int cur_sum = 0;
        int max_sum = -1e9+7;
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