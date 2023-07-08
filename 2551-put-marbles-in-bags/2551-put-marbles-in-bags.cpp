class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
      int n = weights.size();
        priority_queue <int> maxh; 
        priority_queue <int,vector<int>,greater<int>> minh; 
        
        for(int i=1;i<n;i++){
            maxh.push(weights[i]+weights[i-1]);
            minh.push(weights[i]+weights[i-1]);
        }
        
        long long maxSum = 0;
        long long minSum = 0;
        k--; 
        
        while(k--){
            maxSum += maxh.top();
            maxh.pop();
            minSum += minh.top();
            minh.pop();
        }
        
        return maxSum - minSum;
    }
};