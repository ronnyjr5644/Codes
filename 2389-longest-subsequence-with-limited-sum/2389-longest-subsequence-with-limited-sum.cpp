class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
       sort(nums.begin(),nums.end());
        vector<int>res;
        for(int i=0;i<queries.size();i++){
            int sum=0;
            int x=0;
            int count=0;
            while(sum<=queries[i] && x<nums.size()){
               if(sum+nums[x]<=queries[i]){ 
                sum=sum+nums[x];
                count++;
                x++;
               }
                else{
                    break;
                }
            }
            res.push_back(count);
            
        }
        return res;
    }
};