class Solution {
public:
    int minOperations(string s) {
       int n = s.size(), count = 0;;
        if(n == 1) return 0;
        for(int i = 0; i < n; i++) {
            if(i%2 == 0 and s[i] == '1') count++;
            if(i%2 == 1 and s[i] == '0') count++;
        }
        return min(count, n-count);     
    }
};