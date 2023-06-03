//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        int sum1 = 0; 
        int sum2 = 0; 
        int sum3 = 0;
        for(auto i : s1) sum1+= i;
        for(auto i: s2) sum2 += i;
        for(auto i: s3) sum3 += i;
        int i = 0; int j = 0; int k = 0; 
        int ans = 0;
        while(i < n1 and j < n2 and k < n3){
            if(sum1 == sum2 and sum2 == sum3) return sum1;
            int minm = min(sum1,min(sum2,sum3));
            while(i < n1 and sum1 > minm){ sum1-= s1[i]; i++;}
            while(j < n2 and sum2 > minm){ sum2-= s2[j]; j++;}
            while(k < n3 and sum3 > minm){ sum3-= s3[k]; k++;}
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends