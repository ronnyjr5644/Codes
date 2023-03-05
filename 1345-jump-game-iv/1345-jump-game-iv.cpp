class Solution {
public:
    int minJumps(vector<int>& arr) {
         queue<int> q{{0}};
        const int n = arr.size();        
        vector<int> visited(n, 0);
        visited[0]=1;        
        unordered_map<int, vector<int>> equals;
        for(int i = 0; i < n; i++) equals[arr[i]].push_back(i);                
        for(int step = 0;!q.empty(); step++){
            for(int i = q.size(); i>0;i--){
                auto cur = q.front(); q.pop();
                if(cur == n - 1) return step;                
                auto& nexts = equals[arr[cur]];nexts.push_back(cur-1); nexts.push_back(cur+1);
                for(int next: nexts)
                    if(next >=0 && next < n && !visited[next]) q.push(next), visited[next]=1;                     
                
                nexts.clear();                
            }
        }
        return n - 1;
    }
};