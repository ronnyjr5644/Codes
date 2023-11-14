class Solution {
public:
    int countPalindromicSubsequence(string s) {
          int n=s.length();
        int ans=0;
        for(char c='a';c<='z';c++){
            int st=-1,en=-1;
            for(int i=0;i<n;i++){
                if(s[i]==c){
                    st=i;
                    break;
                }
            }
            for(int i=n-1;i>=0;i--){
                if(s[i]==c){
                    en=i;
                    break;
                }
            }
            if(st==-1 || en==-1) continue;
            vector<int>mk(26,0);
            for(int i=st+1;i<=en-1;i++) mk[s[i]-'a']++;
            for(int i=0;i<26;i++){
                if(mk[i]>0) ans++;
            }
        }
        return ans;
    }
};