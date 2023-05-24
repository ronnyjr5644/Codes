class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        priority_queue<pair<int,int>> nums2_max;
        
        for(int i=0;i<n;i++){
            nums2_max.push({nums2[i] , i});
        }
        long long curr_sum = 0 , mini = INT_MAX , ans = 0;
        priority_queue<int,vector<int>,greater<int>>temp;
        while(k--){
            auto top = nums2_max.top();
            nums2_max.pop();
            mini = top.first;
            curr_sum+= nums1[top.second];
            temp.push( nums1[top.second]);
        }
        ans = curr_sum*mini;
        while(nums2_max.size()){
            curr_sum-=temp.top();    temp.pop();
            auto top = nums2_max.top();     nums2_max.pop();
            mini = top.first;
            curr_sum+= nums1[top.second];
            ans = max(ans , curr_sum*mini);
            temp.push(nums1[top.second]);
        }
        return ans;
    }
};