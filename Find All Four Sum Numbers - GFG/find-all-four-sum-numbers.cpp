//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        int n=arr.size();
        int p,q;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                p=j+1;
                q=n-1;
                while(p<q)
                {
                    if(arr[i]+arr[j]+arr[p]+arr[q]==k)
                    {
                    vector<int>nums;
                    nums={arr[i],arr[j],arr[p],arr[q]};
                    ans.push_back(nums);
                   
                    }
                    if(arr[i]+arr[j]+arr[p]+arr[q]<k)
                    p++;
                    else
                    q--;
                }
            }
        }
         sort(ans.begin(), ans.end());

    // Use the unique algorithm to remove duplicates
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends