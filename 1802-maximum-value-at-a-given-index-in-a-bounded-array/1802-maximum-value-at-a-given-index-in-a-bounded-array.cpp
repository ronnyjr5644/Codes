class Solution {
public:
   long sum(long n){ //sum of n numbers
        return (n*(n+1))/2;
    }
    
    int maxValue(int n, int idx, int ms) {
        long l = 1, r=ms, res=0, i=idx, j=n-idx-1;
        
        while(l<=r){
            long mid = l+(r-l)/2, m=mid-1; //mid is the max number we assumed at the index
            long ls = i>=m?(sum(m) + i-m):(sum(m) - sum(m-i)); //finding left sum i.e., mid-1 + mid -2 +...
            long rs = j>=m?(sum(m) + j-m):(sum(m) - sum(m-j));
            // cout<<ls<<" "<<rs<<" "<<mid<<endl;
            if(ls+rs+mid<=ms){ //checking for validity
                res = mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return res;
    }
};