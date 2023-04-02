class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // vector<int>res;
        // for(int i=0;i<spells.size();i++){
        //     int count=0;
        //     for(int j=0;j<potions.size();j++){
        //         if(1LL*spells[i]*potions[j]>=success){
        //             count++;
        //         }
        //     }
        //     res.push_back(count);
        // }
        // return res;
         sort(potions.begin(), potions.end());
        vector<int> res;
        for (int a: spells) {
            long need = (success + a - 1) / a;
            auto it = lower_bound(potions.begin(), potions.end(), need);
            res.push_back(potions.end() - it);
        }
        return res;
    }
};