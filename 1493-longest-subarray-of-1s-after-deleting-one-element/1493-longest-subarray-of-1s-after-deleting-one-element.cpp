class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        vector<int>zeros;
        zeros.push_back(-1);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeros.push_back(i);
            }
        }
        zeros.push_back(n);
        int zerosCount=zeros.size();
        
        for (int i = 1; i < zerosCount - 1; i++) {
            int currLen = zeros[i+1]-zeros[i-1]-2;
            maxi= max(maxi, currLen);
        }
        if (zerosCount == 2)
            return n - 1;
        return maxi;
    }
};