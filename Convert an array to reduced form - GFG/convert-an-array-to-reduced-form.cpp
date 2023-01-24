//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	   int j=n-1;
	   priority_queue<pair<int,int>>pq;
	   for(int i=0;i<n;i++){
	       pq.push({arr[i],i});
	   }
	   while(!pq.empty()){
	       auto x=pq.top();
	       x.first=j;
	       arr[x.second]=x.first;
	       j--;
	       pq.pop();
	   }
	
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends