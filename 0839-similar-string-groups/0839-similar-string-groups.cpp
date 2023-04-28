class Solution {
public:
     bool isSimilar(string& a, string &b) {
        int cnt = 0;
        for(int i=0; i<a.length(); i++)
            if(a[i] != b[i])    cnt++;
        return cnt <= 2;
    }

    void dfs(vector<string>& strs, int ind, vector<bool> &vis) {
        vis[ind] = true;
        for(int i=0; i<strs.size(); i++)  {
            if(isSimilar(strs[ind], strs[i]) && !vis[i])
            dfs(strs, i, vis);
        }
        
    }

    int numSimilarGroups(vector<string>& strs) {
        int ans = 0;
        vector<bool> vis(strs.size(), false);

        for(int i=0; i<strs.size(); i++){
            if(!vis[i]) {
                ans++;
                dfs(strs, i, vis);
            }
        }
        
        return ans;
    }
};