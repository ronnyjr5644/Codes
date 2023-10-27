//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
        int memo[1001][1001];
      int solve(string& s1,string& s2,int i,int j){
        if(i<0 or j<0){
            return 0;
        }
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        if(s1[i]==s2[j]){
            return 1+solve(s1,s2,i-1,j-1);
        }
        return memo[i][j]=max(solve(s1,s2,i-1,j),solve(s1,s2,i,j-1));
    }

    int minimumNumberOfDeletions(string S) { 
        string t=S;
        reverse(t.begin(),t.end());
        int n=S.length();
       memset(memo,-1,sizeof(memo));
        return (n-solve(S,t,n-1,n-1));
        
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends