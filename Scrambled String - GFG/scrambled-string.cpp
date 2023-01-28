//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    unordered_map<string,bool>mp;
    bool isScramble(string a, string b){
    if(a.compare(b)==0) return true;
    if(a.size()<=1) return false;
    string key;
    key=a;
    key.push_back(' ');
    key.append(b);
    if(mp.find(key)!=mp.end()) return mp[key];
    int n=a.size();
    bool flag=false;
    for(int i=1;i<n;i++){
        if((isScramble(a.substr(0,i),b.substr(0,i)) &&isScramble(a.substr(i,n-i),b.substr(i,n-i)))|| (isScramble(a.substr(0,i),b.substr(n-i,i))&& isScramble(a.substr(i,n-i),b.substr(0,n-i)))){
            flag=true;
            break;
        }
    }
    return mp[key]=flag;
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends