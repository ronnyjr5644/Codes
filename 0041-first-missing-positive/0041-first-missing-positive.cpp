class Solution {
public:
    int firstMissingPositive(vector<int>& nums) { 
        int i = 1;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] >= 0)
            {
                if (nums[j] > i)
                    q.push(nums[j]);
                if (i == nums[j])
                    i++;
            }
        }
    while (!q.empty())
        {
            if (q.top() == i)
                i++;
            q.pop();
        }
        return i;
        
        //         priority_queue<int,vector<int>,greater<int>>pq;
//         for(int i=0;i<nums.size();i++){
//             pq.push(nums[i]);
//         }
//         while(!pq.empty()){
//             int x=pq.top();
//             if(x>=0){
//                 break;
//             }
//             pq.pop();
//         }
        
//         int i=0;
//         int y;
//         while(!pq.empty()){
//             y=pq.top();
//             if(y!=i){
//                 break;
//             }
//             i++;
//             pq.pop();
//         }
//         if(pq.empty()==1){
//             return y+1;
//         }
//         else{
//         return pq.top();
//         }
        
    }
};