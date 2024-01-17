class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int>temp;
        set<int>t;
        for(auto it:mp){
            temp.push_back(it.second);
            t.insert(it.second);
        }
        return t.size()==temp.size();
    }
};