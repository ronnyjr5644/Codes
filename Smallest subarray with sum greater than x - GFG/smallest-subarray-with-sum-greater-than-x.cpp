//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x){
        int ans=0;
        int k=0;
        int maxi=1e9+7;
        for(int i=0;i<n;i++){
            ans=ans+arr[i];
            if(ans>x){
                while(ans>x){
                maxi=min(maxi,i-k+1);
                ans=ans-arr[k];
                k++;
                }
            }
        }
        return maxi;
   
   
   
   //wrong approach
    //   priority_queue<int>pq(arr,arr+n);
    //   int i=0;
    //   int temp=0;
    //   while(!pq.empty()){
    //       temp=temp+pq.top();
    //       pq.pop();
    //       i++;
    //       if(temp>x){
    //           return i;
    //       }
    //   }
    //brute force
    // int min_len=n+1;
    // for(int i=0;i<n;i++){
    //     int curr=arr[i];
    //     if(curr>x){
    //         return 1;
    //     }
    //     for(int j=i+1;j<n;j++){
    //         curr=curr+arr[j];
    //         if(curr>x && (j-i+1)<min_len){
    //             min_len=(j-i+1);
    //         }
    //     }
    // }
    // return min_len;
    
  
       
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends