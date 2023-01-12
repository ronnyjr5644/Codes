//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<N;i++){
            pq.push(arr[i]);
        }
        int sum=0;
        int x,y,z;
        while(1){
            if(pq.empty()==0){
                 x=pq.top();
                pq.pop();
            }
            if(pq.empty()==0){
                 y=pq.top();
                pq.pop();
            }
            else{
                break;
            }
             z=x+y;
            sum=sum+z;
            pq.push(z);
            
            
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends