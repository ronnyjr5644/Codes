//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
         vector<int> list;
    list.push_back(H[0]);
    for (int i = 1; i < N; i++) {
        int num = H[i];
        if (num < list[0]) {
            list[0] = num;
        } else if (num > list[list.size() - 1]) {
            list.push_back(num);
        } else {
            auto it = lower_bound(list.begin(), list.end(), num);
            *it = num;
        }
    }
    return N - list.size();
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