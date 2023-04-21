class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        return (x-1)*(y-1);
    }
};