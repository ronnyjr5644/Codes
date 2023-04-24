class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(),stones.end());
        while(pq.size()>=2){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a==b){
                continue;
            }
            else{
                int y=a-b;
                pq.push(y);
            }
                
        }
        if(!pq.empty()){
            return pq.top();
        }
        else{
            return 0;
        }
    }
};