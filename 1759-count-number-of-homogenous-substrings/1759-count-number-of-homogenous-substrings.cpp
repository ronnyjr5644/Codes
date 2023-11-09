class Solution {
public:
    int mod=1e9+7;
    int countHomogenous(string s) {
        int ans = 0;
        int n = s.length();
        for(int i = 1;i<=n;++i){
            int cnt = 1;
            while(i<n && s[i] == s[i-1]){
                cnt++;
                i++;
            }
            ans = ans%mod + ((1LL*cnt*(cnt+1))/2)%mod;
        }
        return ans;
    }
};