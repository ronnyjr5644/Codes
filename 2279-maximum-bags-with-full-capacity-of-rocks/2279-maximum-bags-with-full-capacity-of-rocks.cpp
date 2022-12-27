class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int count=0;
        int n=capacity.size();
        for(int i=0;i<n;i++){
            capacity[i]=capacity[i]-rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        for(int i=0;i<n;i++){
            if(additionalRocks<capacity[i]){
                break;
            }
            count++;
            additionalRocks=additionalRocks-capacity[i];
        }
        return count;
    }
};