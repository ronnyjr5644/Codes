class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        priority_queue<int>res;
        res.push(0);
        int temp=0;
        for(int i=0;i<gain.size();i++){
            temp=temp+gain[i];
            res.push(temp);
        }
        return res.top();
        
    }
};