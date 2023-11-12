class Solution {
public:
       int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int, vector<int>>mp;
        for(int i=0; i<routes.size(); i++){
            for(auto it: routes[i]){
                mp[it].push_back(i);
            }
        }
        int ans=0;
        vector<int>v(routes.size(), 0);
        queue<int>q;
        q.push(source);
        // v[source]=1;
        while(!q.empty()){
            int l=q.size();
            while(l--){
                int num=q.front();
                q.pop();
                if(num==target)return ans;
                vector<int>temp=mp[num];
                for(int i=0; i<temp.size(); i++){
                    if(v[temp[i]])continue;
                    v[temp[i]]=1;
                    for(auto it: routes[temp[i]]){q.push(it);}
                }
            }
            ans++;
        }
        return -1;
    }
};