class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
         vector<int>arr;
        if(pref.size() == 0){
            return arr;
        }
        arr.push_back(pref[0]);
        for(int i = 0; i<pref.size()-1; i++){
            arr.push_back(pref[i] ^ pref[i+1]);
        }
        return arr;
    }
};