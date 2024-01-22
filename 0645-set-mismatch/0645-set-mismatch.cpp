class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n=nums.size();
        long long s1=n*(n+1)/2;
        long long s2=n*(n+1)*(2*n+1)/6;
        long long x1=0,x2=0;
        for(int i=0;i<n;i++){
            x1+=nums[i];
            x2+=(nums[i]*nums[i]);
        }
        long long d1=x1-s1;
        long long d2=x2-s2;
        long long d=d2/d1;
        long long rep=(d1+d)/2;
        long long num=abs(d-rep);

        vector<int> ans{int(rep),int(num)};
        return ans;
    }
};