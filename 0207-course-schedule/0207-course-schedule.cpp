class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
           vector<int> ans;
        unordered_map<int,vector<int>> mp;
        vector<int> res(num,0);
        for(auto &x:pre){
            mp[x[1]].push_back(x[0]);
            res[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(res[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int fr=q.front();
            q.pop();
            ans.push_back(fr);
            for(auto &x:mp[fr]){
                res[x]--;
                if(res[x]==0){
                    q.push(x);
                }
            }
        }
        if(ans.size()==num){
            return true;
        }
        return false;
    }
};