class Solution {
public:
      vector<int> getAverages(vector<int>& v, int k) {
        int n=v.size();
        vector<int>a(n,-1);
        int l=0,r=0;
        long long sum=0;
        while(r<n){
            sum += v[r];
            if((r-l+1)==(2*k+1)){
                a[r-k] = sum/(2*k+1);
                sum -= v[l];
                l++; 
            }
            r++;
        }
        return a;
    }
};