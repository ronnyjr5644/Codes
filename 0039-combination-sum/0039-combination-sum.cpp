class Solution {
public:
    void Sum(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& temp, int i){ 
        if(target == 0){
            res.push_back(temp);
            return;
        }
        while(i <  candidates.size() && target-candidates[i] >= 0){
            temp.push_back(candidates[i]);
            Sum(candidates,target - candidates[i],res,temp,i);
            i++;
            temp.pop_back();
        }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end()); 
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        vector<int> temp;
        vector<vector<int> > res;
        
        Sum(candidates,target,res,temp,0);
        
        return res;
    }
};