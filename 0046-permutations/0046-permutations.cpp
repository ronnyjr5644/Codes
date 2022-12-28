class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        res.push_back(nums);
        vector<int>temp=nums;
        while(1){
            next_permutation(nums.begin(),nums.end());
            if(temp==nums){
                break;
            }
            res.push_back(nums);
        }
        return res;
    }
};