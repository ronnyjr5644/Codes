//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        int n = str.size(),i;
        for(i=1;i<n;i++)
        {
            if(str[i]>str[i-1])break;
            if(i==1 && str[i]==str[i-1])break;
        }
        string temp = str.substr(0,i);
        string ans = temp;
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends