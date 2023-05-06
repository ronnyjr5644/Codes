class Solution {
public:
    int power(long long x, long long y, long long p)
    {
        long long res = 1;
        x = x % p;
        if (x == 0) return 0;
        while (y > 0)
        {
            if (y & 1)
                res = (res*x) % p;
            y = y>>1;
            x = ((x%p)*(x%p)) % p;
        }
        return (int)(res%p);
    }
    
    int numSubseq(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        int ans = 0, mod = 1e9+7, l=0, r=a.size();
        for(int i=0;i<r;i++){
            int idx = upper_bound(a.begin(), a.end(), target-a[i]) - a.begin();
            if(a[i]*2<=target) {
                ans+=1;
            }
            if(idx>=0 && idx==a.size() || a[idx] != target-a[i]) idx--;
            if(idx<i) continue;
            ans = ((ans%mod)+(power(2, idx - i, mod)%mod)%mod) - 1;
        }
        return ans;
    }
};