//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
      int merge(vector<int> &arr,int low,int mid,int high){
        int cnt=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
         while(j<=high && arr[i]>2LL*arr[j]){
             j++;
         }
          cnt+=( j-(mid+1));  
        }
        vector<int> temp;
        int left=low,right=mid+1;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left++]);
            }
            else{
                temp.push_back(arr[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(arr[left++]);
        }
        while(right<=high){
            temp.push_back(arr[right++]);
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        return cnt;
    }
  int mergeSort(vector<int> &arr,int low,int high){
        int inv,mid;
      if(low>=high) return 0;
      mid=(low+high)/2;
      inv=mergeSort(arr,low,mid);
      inv+= mergeSort(arr,mid+1,high);
      inv+=  merge(arr,low,mid,high);
      return inv;
    }
    
 int countRevPairs(int n, vector<int> arr) {
        return mergeSort(arr,0,arr.size()-1);
    }
   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends