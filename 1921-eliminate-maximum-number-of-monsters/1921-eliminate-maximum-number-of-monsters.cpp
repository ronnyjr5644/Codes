class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> ds(n);
        for(int i=0;i<n;i++){
            ds[i] = ceil((double)dist[i]/speed[i]);
        }
        sort(ds.begin(), ds.end());
        int ans = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            if(ds[i]>ans){
                ans++;
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
};