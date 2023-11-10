class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> map;
        for(auto pair : adjacentPairs){
            map[pair[0]].push_back(pair[1]);
            map[pair[1]].push_back(pair[0]);
        }
        int curInt = 0, preInt = 0;
        for(auto e : map)
            if(e.second.size()==1){
                curInt = preInt = e.first;
                break;
            }
        vector<int> ans{curInt};
        while(ans.size()<map.size()){
            int nextInt = (map[curInt][0] == preInt? map[curInt][1] : map[curInt][0]);
            preInt = curInt; 
            curInt = nextInt;
            ans.push_back(curInt);
        }
        return ans;
    }
};