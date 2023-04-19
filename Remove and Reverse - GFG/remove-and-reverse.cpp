//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        
        int n = S.size();
        unordered_map<char,int> mp;
        for(auto it:S) {
            mp[it]++;
        }
        
        int fr = 0;
        int bk  = n-1;
        
        while(fr<=bk){
            while(mp[S[fr]]<2){
                fr++;
                if(fr>bk || fr>S.size()-1) return S;
            }
            mp[S[fr]]--;
            S.erase(S.begin()+fr);
            
            while(mp[S[bk]]<2){
                bk--;
                if(bk<fr || bk<0){
                    reverse(S.begin(),S.end());
                    return S;
                }
            }
            mp[S[bk]]--;
            S.erase(S.begin()+bk);
        }
        return S;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends