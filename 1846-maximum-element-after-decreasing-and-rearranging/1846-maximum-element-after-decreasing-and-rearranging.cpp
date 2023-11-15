class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int j = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= j) {
                arr[i] = j;
                j++;
            }
        }
        return arr[arr.size()-1];
    }
};