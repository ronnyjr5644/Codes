class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(),piles.end()); 
        int res=0;
        for(int i=0;i<k;i++){
            int x=pq.top(); 
            pq.pop();
            x=x-(x/2);   
            pq.push(x);
        }
        while(!pq.empty()){
            res=res+pq.top();   
            pq.pop();
        }
        return res;
    }
};