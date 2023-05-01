class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        int n=salary.size();
        double k;
        int temp=0;
        for(int i=1;i<n-1;i++){
            temp=temp+salary[i];
            
        }
        
        
        k=(double)temp/(n-2);
        return k;
    }
};