//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        int ma = arr[0], mi = arr[0], res = 0;
        for(int i=0; i<n; i++) {
            res = max(res, max(ma-arr[i], arr[i]-mi)+i);
            mi = min(mi, arr[i]+i);
            ma = max(ma, arr[i]-i);
        }
        return res;
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends