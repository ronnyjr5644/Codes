class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
          map<int,vector<int> >m;
        for(int i=0;i<arr.size();i++){
            m[__builtin_popcount(arr[i])].push_back(arr[i]); 
        }
        vector<int>ans;
        for(auto a:m){
            sort(a.second.begin(),a.second.end());
            for(int j=0;j<a.second.size();j++){
                ans.push_back(a.second[j]);
            }
        }
        return ans;
        
    }
};