//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
       vector<int> v;
        for(int i=0;i<N;i++){
            int n=v.size(),x=asteroids[i];
            if(n==0){
                v.push_back(asteroids[i]);
            }
            else if(v[n-1]<0 || x>0){
                v.push_back(asteroids[i]);
            }
            else if(v[n-1]+x==0){
                v.pop_back();
            }
            else if(v[n-1]+x<0){
                v.pop_back();
                i--;
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends