class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), condition);
        int ans = 0;
        vector<int>& pair = pairs[0];
        for (int i = 0; i < pairs.size(); i++) {
            if (i == 0 || pairs[i][0] > pair[1]) {
                pair = pairs[i];
                ans++;
            }
        }
        return ans;
    }

private:
    static bool condition(vector<int>& a, vector<int>&b) {
        return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
    }
};