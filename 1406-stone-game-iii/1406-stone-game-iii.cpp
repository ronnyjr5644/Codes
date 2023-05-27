class Solution {
public:
    string stoneGameIII(vector<int>& v) {
        int i1=0,i2=0,i3=0;
        int n=v.size();
        int i=n-1;
        while(i>=0){
            int ans=INT_MIN;
            ans=max(ans,v[i]-i1);
            if(i+1<v.size())ans=max(ans,v[i]+v[i+1]-i2);
            if(i+2<v.size())ans=max(ans,v[i]+v[i+1]+v[i+2]-i3);
              i--;
            i3=i2;
            i2=i1;
            i1=ans;
        }
        int diff=i1;
        if(diff>0)return "Alice";
        else if(diff<0)return "Bob";
        else return "Tie"; 
    }
};