//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
         int mx=*max_element(arr,arr+n);
        if(mx<0){
            return mx;
        }
        long long int max_so_far=INT_MIN;
        long long int curr_max=0;
        for(int i=0;i<n;i++){
            curr_max+=arr[i];
            if(curr_max>max_so_far){
                max_so_far=curr_max;
            }
            if(curr_max<0){
                curr_max=0;
            }
        }
        return max_so_far;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends