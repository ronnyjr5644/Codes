//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
       sort(words.begin(),words.end());
        string result;
        for (string s:words){
            bool isPrefixPresent=true;
            for (int i=1;i<s.size();i++){
                 if (!binary_search(words.begin(),words.end(),s.substr(0,i))){
                    isPrefixPresent=false;
                     break;
                }
             }
            if (isPrefixPresent && s.size() > result.size()){
                result=s;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends