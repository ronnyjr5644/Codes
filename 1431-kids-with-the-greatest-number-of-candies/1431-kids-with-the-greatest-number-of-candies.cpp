class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>res;
        int x=*max_element(candies.begin(), candies.end());
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=x){
                res.push_back(1);
            }
            else{
                res.push_back(0);
            }
        }
        return res;
    }
};