class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            
            mp[temp].push_back(i);
        }
        
        vector<vector<string>> ans;
        for(auto it:mp)
        {
            vector<string> tempAns;
            for(int i=0;i<it.second.size();i++)
            tempAns.push_back(strs[it.second[i]]);
            
            ans.push_back(tempAns);
        }
        return ans;
    }
};