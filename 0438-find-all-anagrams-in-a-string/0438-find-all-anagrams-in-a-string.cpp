class Solution {
public:
    bool isAnagram(int fs[],int fp[]){
        for(int i=0;i<26;i++){
            if(fs[i]!=fp[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n=s.size();
        int m=p.size();
        int fs[26]={0};
        int fp[26]={0};
        for(int i=0;i<m;i++){
            fp[p[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            if(i<m-1){
                fs[s[i]-'a']++;
            }
            else if(i==m-1){
                fs[s[i]-'a']++;
                if(isAnagram(fs,fp)){
                    ans.push_back(i-m+1);
                }
            }
            else{
                fs[s[i-m]-'a']--;
                fs[s[i]-'a']++;
                if(isAnagram(fs,fp)){
                    ans.push_back(i-m+1);
                }
            }
        }
        return ans;
    }
};