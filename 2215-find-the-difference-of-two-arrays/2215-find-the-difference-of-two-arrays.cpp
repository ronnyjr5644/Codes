class Solution {
public:
    void findMissingNums(const vector<int>& nums1, const vector<int>& nums2,vector<vector<int>>&res) {
    vector<int> missingNums;
    unordered_set<int> nums2Set(nums2.begin(), nums2.end());

    for (int num : nums1) {
        if (nums2Set.find(num) == nums2Set.end()) {
            missingNums.push_back(num);
        }
    }
    unordered_set<int>st(missingNums.begin(),missingNums.end());
    vector<int>x(st.begin(),st.end());
    res.push_back(x);
}
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>res;
        findMissingNums(nums1,nums2,res);
        findMissingNums(nums2,nums1,res);
        return res;
        
        
    }
};