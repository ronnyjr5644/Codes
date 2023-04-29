class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char,int> m;
        for(auto& it : word1){
            m[it]++;
        }
        for(auto& it : word2){
            m[it]--;
        }
        for(auto& it :m){
            if(abs(it.second)>3) return false;
        }
        return true;
    }
};