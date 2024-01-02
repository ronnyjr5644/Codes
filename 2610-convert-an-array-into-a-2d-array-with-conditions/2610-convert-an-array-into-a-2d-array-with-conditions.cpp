class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
     map<int,int> m;
        int maxi = INT_MIN;
        for(auto i:nums){
            m[i]++;
            if(maxi<m[i]){
                maxi=m[i];
            }
        }
        
        vector<vector<int>> arr;
        
        
        for(int i=0;i<maxi;i++){
           vector<int> e;
        for (auto it = m.begin(); it != m.end(); it++) {
            if(m[it->first]!=0){
        e.push_back(it->first);
            m[(it->first)]--;
            }
    }
            arr.push_back(e);
        }        
        
       return arr;
    }
};