//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        // vector<int>res;
        // res.push_back(-1);
        // res.push_back(-1);
        // int l=INT_MAX;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         l=min(l,abs(x-(arr[i]+arr[j])));
        //         if(abs(x-(arr[i]+arr[j]))<l){
        //         res[0]=arr[i];
        //         res[1]=arr[j];
        //         }
        //     }
        // }
        // sort(res.begin(),res.end());
        // return res;
        vector<int> ans(2,0);
        int i=0,j=m-1;
        int mini_diff=INT_MAX;
        while(i<n && j>=0){
            int sum=arr[i]+brr[j];
            if(mini_diff>(abs(x-sum))){
                mini_diff=abs(sum-x);
                ans[0]=arr[i];
                ans[1]=brr[j];
            }
            if(sum>x)
            j--;
            else
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends