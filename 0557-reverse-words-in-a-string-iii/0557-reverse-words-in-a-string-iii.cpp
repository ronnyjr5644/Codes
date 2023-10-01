class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0;
        for (int end = 0; end < n; end++) {
            if (s[end] == ' ' || end == n - 1) {
                int left = start;
                int right = (end == n - 1) ? end : end - 1;

                while (left < right) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }

                start = end + 1;
            }
        }

        return s;

    }
};