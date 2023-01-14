//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long subarraySum(long long arr[], long long n)
    {
       long long int sum = 0;
    int mod=1e9+7;
    for(int i=0;i<n;i++){
        sum = (sum%mod + arr[i]%mod * (n-i) * (i + 1))%mod;
    }
    return sum%mod;
    }
    
};

//{ Driver Code Starts.
int main()
 {
     long long t; 
     cin>>t;
     while(t--)
     {
         long long n; cin>>n;
         long long a[n+5];
         for(long long i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.subarraySum(a, n)<<endl;
     }
    return 0;
}

// } Driver Code Ends