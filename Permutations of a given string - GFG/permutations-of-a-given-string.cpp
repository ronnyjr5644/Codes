//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    vector<string>res;
		    res.push_back(S);
		    string temp=S;
		    next_permutation(temp.begin(),temp.end());
		    if(S==temp){
		        return res;
		    }
		    else{
		        res.push_back(temp);
		    }
		    
		    while(1){
		        next_permutation(temp.begin(),temp.end());
		        if(temp==S){
		            break;
		        }
		        else{
		            res.push_back(temp);
		            
		        }
		    }
		    sort(res.begin(),res.end());
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends