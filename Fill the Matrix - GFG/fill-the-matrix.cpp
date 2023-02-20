//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        int arr[N][M];
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                arr[i][j]=0;
            }
        }
        arr[x-1][y-1]=1;
        int res=0;
        int row[4]={-1,0,0,1};
        int col[4]={0,1,-1,0};
        queue<pair<pair<int,int>,int>>q;
        q.push(make_pair(make_pair(x-1,y-1),0));
        while(!q.empty()){
            res=q.front().second;
            for(int i=0;i<4;i++){
                int a=q.front().first.first+row[i];
                int b=q.front().first.second+col[i];
                if(a<0 || b<0 || a>=N || b>=M){
                    continue;
                }
                if(arr[a][b]==0){
                    q.push(make_pair(make_pair(a,b),q.front().second+1));
                    arr[a][b]=1;
                }
                
                
            }
            q.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends