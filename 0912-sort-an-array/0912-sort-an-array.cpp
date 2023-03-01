class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int j=0;
        while(!pq.empty()){
            nums[j]=pq.top();
            pq.pop();
            j++;
        }
        return nums;
    }
};