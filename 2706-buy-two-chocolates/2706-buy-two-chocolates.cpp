class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        priority_queue<int, vector<int>,greater<int>>pq;
        for(int i=0;i<prices.size();i++){
            pq.push(prices[i]);
        }
  
       int val1 = pq.top();
        pq.pop();
        int val2 = pq.top();
        if( money - (val2+val1)  < 0){
            return money;
        }
        return money- (val1+val2);
        
        
        
    }
};