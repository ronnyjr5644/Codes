class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string str = "";
        for(int i = 0 ; i<nums.size();i++)
        {
            char ch = nums[i][i];
            str += ch == '0' ? '1' : '0';
        } 
        return str;
    }
};