//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool function(int a, int b) {
        if((a < 0 && b < 0) || (a >= 0 && b >= 0)) return false;
        return true;
    }
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            if (!st.empty() && function(st.top(), arr[i]))
                st.pop();
            else
                st.push(arr[i]);
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends