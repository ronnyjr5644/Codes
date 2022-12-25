//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
     bool checkrow(vector<vector<int> >& a, int n){
        int p=0;
        for(int i=0;i<n;i++){
            p+=a[0][i];
        }
        for(int i=0;i<n;i++){
            int q=0;
            for(int j=0;j<n;j++){
                q+=a[i][j];
            }
            if(q!=p){
                return false;
            }
        }
        return true;
    }
    bool checkcol(vector<vector<int> >& a, int n){
        int p=0;
        for(int i=0;i<n;i++){
            p+=a[i][0];
        }
        for(int i=0;i<n;i++){
            int q=0;
            for(int j=0;j<n;j++){
                q+=a[j][i];
            }
            if(q!=p){
                return false;
            }
        }
        return true;
    }
    bool checkdia(vector<vector<int> >& a, int n){
        int p=0,q=0;
        for(int i=0;i<n;i++){
            p+=a[i][n-1-i];
        }
        for(int i=0;i<n;i++){
            q+=a[i][i];
        }
        return (p==q);
    }
    long long int MissingNo(vector<vector<int> >& a){
    long long int ans=0,p,q;
    int n=a.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0){
                p=i;
                q=j;
            }
        }
    }
    if(p==0){
        for(int i=0;i<n;i++){
            ans+=(a[1][i]-a[0][i]);
        }
        a[p][q]=ans;
    }
    else{
        for(int i=0;i<n;i++){
            ans+=(a[0][i]-a[p][i]);
        }
        a[p][q]=ans;
    }
    if(checkrow(a,n) && checkcol(a,n) && checkdia(a,n) && ans>0){
        return ans;
    }
    return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends