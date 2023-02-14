//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int n) {
        vector<int>dp1(n);
        vector<int>dp2(n);
        vector<int>dp3(n);
        dp1[0]=colors[0][0];
        dp2[0]=colors[0][1];
        dp3[0]=colors[0][2];
        for(int i=1;i<n;i++){
            dp1[i]=colors[i][0]+min(dp2[i-1],dp3[i-1]);
            dp2[i]=colors[i][1]+min(dp1[i-1],dp3[i-1]);
            dp3[i]=colors[i][2]+min(dp1[i-1],dp2[i-1]);
        }
        return min({dp1[n-1],dp2[n-1],dp3[n-1]});
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends