
        typedef long long ll;


// Bruteforce | O(n^4) time | O(n) space
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int l = j + 1, r = n - 1;
                ll remSum = (ll)target - (ll)nums[i] - (ll)nums[j];
                while (l < r) {
                    ll sumOfLastTwo = nums[l] + nums[r];
                    if (sumOfLastTwo < remSum) l++;
                    else if (sumOfLastTwo > remSum) r--;
                    else {
                        vector<int> quad = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(quad);
                        while (l < r && nums[l] == quad[2]) l++;
                        while (l < r && nums[r] == quad[3]) r--;
                    }
                }
                while (j < n - 1 && nums[j] == nums[j + 1]) j++;
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
};
    