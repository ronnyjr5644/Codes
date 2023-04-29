class Solution {
public:
    bool equalFrequency(string word) {
         vector<int> v;
        unordered_map<char,int> m;
        for(auto& i : word){
            m[i]++;
        }
        for(auto& itr : m){
            v.push_back(itr.second);
        }
        int l=v.size();
        for(int i=0; i<l; ++i){
            v[i] -= 1;
            unordered_set<int> s;
            for(auto& itr : v){
                if(itr>0) s.insert(itr);
            }
            if(s.size() == 1) return true;
            v[i] += 1;
            s.clear();
        }
        return false;
    }
};