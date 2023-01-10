//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
       //brute force approach 
        // unordered_map<int,int>mp;
        // for(int i=0;i<N;i++){
        //     mp[arr[i]]++;
        // }
        // sort(arr.begin(),arr.end());
        // long long int ans=0;
        // int i=1;
        // for(auto it:mp){
        //     while(it.second>1){
        //         int temp=it.first;
        //         it.second--;
        //         while(mp[temp]){
        //             ans++;
        //             temp++;
        //         }
        //         mp[temp]++;
        //     }
            
        // }
        // return ans;
        sort(arr.begin(),arr.end());
        long long int res=0;
        for(int i=1;i<arr.size();i++){
            while(arr[i]<=arr[i-1]){
                arr[i]++;
                res++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends