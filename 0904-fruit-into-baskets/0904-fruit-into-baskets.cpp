class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mp;
        int i=0;
        int j=0;
        int ans=0;
        while(j<fruits.size()){
            mp[fruits[j]]++;
            while(mp.size()>2){
                if(mp[fruits[i]]==1){
                    mp.erase(fruits[i]);
                }
                else{
                    mp[fruits[i]]--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
            
            
        }
        return ans;
        // for(int i=0;i<fruits.size();i++){
        //     mp[fruits[i]]++;
        // }
        // priority_queue<pair<int,int>>pq;
        // for(auto it:mp){
        //     pq.push(make_pair(it.second,it.first));
        // }
        // int res=0;
        // auto x=pq.top();
        // pq.pop();
        // auto y=pq.top();
        // pq.pop();
        // res=x.first+y.first;
        // return res;
    }
};