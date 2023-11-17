class Solution {
public:
    int minPairSum(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int x=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int m=pq.top()+nums[i];
            x=max(m,x);
            pq.pop();
        }   
        return x;

    }
};