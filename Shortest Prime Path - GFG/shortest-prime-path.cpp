//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    int shortestPath(int Num1,int Num2)
    {   
  queue<pair<int, int>> q;
  q.push({Num1, 0});
  unordered_set<int> st;
  st.insert(Num1);
  bool prime[10000];
  memset(prime, 1, sizeof(prime));
  for (int p = 2; p * p <= 9999; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= 9999; i += p)
        prime[i] = false;
    }
  }
  while (!q.empty()) {
    int num = q.front().first;
    int dist = q.front().second;
    q.pop();
    if (num == Num2) {
      return dist;
    }
    for (int i = 1; i <= 4; i++) {
      for (int d = 0; d <= 9; d++) {
        int placeValue = pow(10, 4 - i);
        int digit = (num / placeValue) % 10;
        int newNum = num - digit * placeValue + d * placeValue;
        if (st.find(newNum) == st.end() && prime[newNum] == true && newNum > 999 && newNum < 10000) {
          q.push({newNum, dist + 1});
          st.insert(newNum);
        }
      }
    }
  }
  return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends