//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void precompute()
    {
        // Code Here
    }
    
long long solve(long long l, long long r){
      long long i = 1;
      long long cnt = 0;
while (i < r){
    long long j = i << 1;
    while (j < r){
        long long k = j << 1;
        while (k < r){
            long long tmp = i | j | k;
            if (l <= tmp && tmp <= r)
                ++ cnt;
            k <<= 1;
        }
        j <<= 1;
    }
    i <<= 1;
}
return cnt;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends