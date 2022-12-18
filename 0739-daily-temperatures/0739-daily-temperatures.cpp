class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //vector<int>res;
        // stack<int>st1;
        // stack<int>st2;
       //brute force
//         int n=temperatures.size();
//         for(int i=0;i<n;i++){
//             int count=0;
//             bool flag=false;
//             for(int j=i+1;j<n;j++){
//                 if(temperatures[i]<temperatures[j]){
//                     count++;
//                     flag=true;
//                     break;
//                 }
               
//                 else{
//                     count++;
                    
//                 }
//             }
//             if(flag==true){
//             res.push_back(count);
//             }
//             else{
//                 res.push_back(0);
//             }
//         }
//         return res;
        
        int n= temperatures.size();
        vector<int> res(n,0);
    
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        
        
        for(int i=0;i<n-1;++i) {
            while(!pq.empty() && pq.top().first < temperatures[i+1]) {
                    pair<int,int> top = pq.top();
                    pq.pop();
                    res[top.second] = i+1 - top.second;
            }
            if(temperatures[i] < temperatures[i+1]) {
                res[i] = 1;
            }
            else {
                pq.push(make_pair(temperatures[i],i));
            }
        }
        return res;
    }
};