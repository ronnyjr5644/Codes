class Solution {
public:
    long long zeroFilledSubarray(vector<int>& arr) {
        int n=arr.size();
         long long ans=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        { 
            ans+=(cnt*(cnt+1)/2); 
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    if(arr[n-1]==0) ans+=(cnt*(cnt+1)/2);
    return ans;
    }
};