class Solution {
public:
    int maxProfit(vector<int>& prices) {
         priority_queue<int, vector<int>, greater<int> > minPrice;
        
        minPrice.push(INT_MAX);
        
        int MaxProfit=0;
        
        for(auto& curr : prices)
        {
            minPrice.push(curr);
            
            if(curr> minPrice.top())
            {   
                
                MaxProfit = max( MaxProfit, curr-minPrice.top() );
            }
        }
        
        return MaxProfit;
    }
};