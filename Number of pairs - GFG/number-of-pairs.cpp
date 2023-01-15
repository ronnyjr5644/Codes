//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long countPairs(int X[], int Y[], int m, int n) {
       vector<double>x;
        vector<double>y;
        for(int i = 0; i<m; i++)
        {
            double temp1 = (double)X[i]/(double)log(X[i]);
            x.push_back(temp1);
        }
        
        for(int i = 0; i<n; i++)
        {
            double temp2 = (double)Y[i]/(double)log(Y[i]);
            y.push_back(temp2);
        }
        
        sort(x.begin(),x.end());
        sort(y.begin(), y.end());
        
        long long int ans = 0;
        for(auto z : y)
        {
            long long int temp3 = lower_bound(x.begin(),x.end(),z) - x.begin();
            ans = ans + temp3;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int X[m], Y[n];
        for (int i = 0; i < m; i++) {
            cin >> X[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> Y[i];
        }
        Solution ob;
        auto ans = ob.countPairs(X, Y, m, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends