//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  int t[1002][1002];
    
  public:
    int helper(int price[], int length[], int n, int i){
        if(n == 0 || i == 0) return 0; 
        
        if(t[n][i] != -1) return t[n][i]; 
        
        if(length[n-1] <= i){
           
            return t[n][i] = max(price[n-1]+helper(price, length, n, i-length[n-1]), helper(price, length, n-1, i));
        }
        else return t[n][i] = helper(price, length, n-1, i);
    }
  
    int cutRod(int price[], int n) {
        memset(t, -1, sizeof(t));
        int length[n];
        for(int i=0;i<n;i++) length[i] = i+1;
        return helper(price, length, n, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends