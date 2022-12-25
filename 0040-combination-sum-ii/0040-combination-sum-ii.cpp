class Solution {
public:
    void solve(vector<int>&candidates,int target,vector<int>&temp,vector<vector<int>>&res,int idx){
        if(target==0){
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
             if(candidates[i] > target){
                 break;
             }
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],temp,res,i+1);
            temp.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>temp;
        solve(candidates,target,temp,res,0);
        return res;
    }
};