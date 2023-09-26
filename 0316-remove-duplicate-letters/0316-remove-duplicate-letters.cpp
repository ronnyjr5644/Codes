class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> seen(26, 0);
        stack<int> st;

        for (char c : s)
            freq[c-'a']++;
        deque<char> ans;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            freq[c-'a']--;
            if (seen[c - 'a']) continue;
            while (!st.empty()&& c< s[st.top()] && freq[s[st.top()]-'a'] > 0) {
                seen[s[st.top()]-'a'] = 0;
                st.pop();
            }
            st.push(i);
            seen[c-'a'] = 1;
        }
        while (!st.empty()) {
            ans.push_front(s[st.top()]);
            st.pop();
        }
        
        return string(ans.begin(), ans.end());
    }
};