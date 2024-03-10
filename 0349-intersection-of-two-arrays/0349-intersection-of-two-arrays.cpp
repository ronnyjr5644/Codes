class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>st1(nums1.begin(),nums1.end());
        set<int>st2(nums2.begin(),nums2.end());
        vector<int>res;
        unordered_map<int,int>mp;
        for(auto it:st1){
            mp[it]++;
        }
        for(auto it:st2){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second==2){
                res.push_back(it.first);
            }
        }
        return res;
    }
};