class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
//         if(tasks.size()==1){
//             return -1;
//         }
//         unordered_map<int,int>mp;
//         for(int i=0;i<tasks.size();i++){
//             mp[tasks[i]]++;
//         }
//         set<int>st;
//         for(auto it:mp){
//             if(it.second==4){
//                 st.insert(it.first);
//             }
//             if(it.second==1){
//                 return -1;
//             }
//         }
//         priority_queue<int,vector<int>,greater<int>>pq;
//         for(int i=0;i<tasks.size();i++){
//             pq.push(tasks[i]);
//         }
//         int res=0;
        
//         while(!pq.empty()){
//             int x=pq.top();
//             pq.pop();
          
//             res++;
//             if(st.find(x)!=st.end()){
                
//                    if(pq.empty()==0){
                       
//                 int y=pq.top();
//                 pq.pop();
                    
                  
//             }
//             }
//             else{
                  
//             for(int i=0;i<2;i++){
                
//                 if(pq.empty()==0){
//                 int y=pq.top();
//                 pq.pop();
                    
//                     if(x==y){
//                     continue;
//                 }
//                 else{
//                     break;
//                 }
//                 }
                
//             }
//             }
//         }
        
//         return res;
        int ans = 0;
        unordered_map<int,int>mp;
        for(int x: tasks){
            mp[x]++;
        }
        
        for(auto x: mp){
            if(x.second == 1){
                return -1;
            }
            
            else{
                int rem = x.second%3;
                int usedrounds = x.second/3;
                ans+=usedrounds;
                if(rem == 1){
                    ans-=1;
                    ans+=2;
                }
                
                else if(rem == 2){
                   ans+=1;
                }
            }
        }
        return ans;   
    }
};