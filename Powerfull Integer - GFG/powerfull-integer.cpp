//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &i,int k){
       map <int , int> mp ;
        for(int j = 0 ; j < n ; j++){
            mp[i[j][0]]++ ;
            mp[i[j][1]+1]-- ;
        }
        int cnt = 0 , ans = -1 ;
        for(auto &x : mp){
            if(cnt >= k){
                ans = max(ans , x.first - 1) ;
            }
            cnt += x.second ;
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends