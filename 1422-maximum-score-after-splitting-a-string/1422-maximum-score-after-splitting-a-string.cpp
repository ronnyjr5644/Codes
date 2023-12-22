class Solution {
public:
    int maxScore(string s) {
        int maxi=INT_MIN;
       vector<int>zero(s.size(),0);
        int zeros=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                zeros++;
            }
            zero[i]=zeros;
    }
        int ones=0;
        int ans=0;
        for(int i=s.size()-1;i>0;i--){
            if(s[i]=='1'){
                ones++;
            }
            int temp=zero[i-1]+ones;
            ans=max(ans,temp);
        }
        return ans;
    }
};