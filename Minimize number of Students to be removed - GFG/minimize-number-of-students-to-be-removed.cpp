//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
   
    int dp[N + 1];
    int ans = 0;
    fill(dp, dp + N + 1, INT_MAX);
    dp[0] = INT_MIN;
    for (int i = 0; i < N; i++) {
        int key = H[i];
        int low = 0, high = N + 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (dp[mid] >= key && dp[mid - 1] < key) {
                dp[mid] = key;
                break;
            } else if (dp[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    for (int i = N; i >= 0; i--) {
        if (dp[i] != INT_MAX) {
            ans = i;
            break;
        }
    }
    return N - ans;
     //      vector<int> list;
    // list.push_back(H[0]);
    // for (int i = 1; i < N; i++) {
    //     int num = H[i];
    //     if (num < list[0]) {
    //         list[0] = num;
    //     } else if (num > list[list.size() - 1]) {
    //         list.push_back(num);
    //     } else {
    //         auto it = lower_bound(list.begin(), list.end(), num);
    //         *it = num;
    //     }
    // }
    // return N - list.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends