class Solution {
public:
   long sum(long n){ 
        return (n*(n+1))/2;
    }
    
    int maxValue(int n, int idx, int ms) {
        long l = 1, r=ms, res=0, i=idx, j=n-idx-1;
        
        while(l<=r){
            long mid = l+(r-l)/2, m=mid-1; 
            long ls = i>=m?(sum(m) + i-m):(sum(m) - sum(m-i)); 
            long rs = j>=m?(sum(m) + j-m):(sum(m) - sum(m-j));
        
            if(ls+rs+mid<=ms){ 
                res = mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return res;
    }
};