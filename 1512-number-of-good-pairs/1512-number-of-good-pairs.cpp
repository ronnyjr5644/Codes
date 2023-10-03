class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num: nums) mp[num]++;
        int result = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            int mx = it->second - 1;
            result += (1 + mx) * mx / 2;
        }
        return result;
    }
};