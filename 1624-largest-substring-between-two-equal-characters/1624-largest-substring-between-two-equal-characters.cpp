class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        std::unordered_map<char, int> mp;
        int len = -1;
        for(int i = 0; i < s.length(); i++) {
            if(mp.count(s[i])) len = max(len, i - mp[s[i]] - 1);
            else mp[s[i]] = i;
        }
        return len;
    }
};