class Solution {
public:
    bool makeEqual(vector<string>& words) {
         int cnt[26] = {0};
 
        for (auto &w : words)
           for (auto ch : w)
               ++cnt[ch - 'a'];
        
        
        int n=words.size();
        for(int i: cnt)
            if(i%n!=0) return false;
        return true;
    }
};