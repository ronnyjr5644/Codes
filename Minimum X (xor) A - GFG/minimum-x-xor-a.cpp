//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int bitcounta=__builtin_popcount(a);
        int bitcountb=__builtin_popcount(b);
        int diff=abs(bitcounta-bitcountb);
        if(diff==0){
            return a;
        }
        else if(bitcounta>bitcountb){
            while(diff>0){
                a=a&a-1;
                diff--;
            }
        }
        else{
            while(diff>0){
                a=a|(a+1);
                diff--;
            }
        }
        return a;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends