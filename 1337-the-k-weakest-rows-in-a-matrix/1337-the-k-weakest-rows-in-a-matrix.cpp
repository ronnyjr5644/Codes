class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
          int n = mat.size();
        int m = mat[0].size();
        
        vector<pair<int,int>> soldiers(n);
        
        int i = 0;
        for(auto it : mat){
            for(int j = 0; j<m; j++){
                if(it[j] == 0){
                    soldiers[i] = {j,i};
                    break;
                }
                else if(j == m-1)
                    soldiers[i] = {m,i};
            }
            i++;
        }
        
        sort(soldiers.begin(), soldiers.end());
        
        vector<int> ans(k);
        for(int i = 0; i<k; i++){
            ans[i] = soldiers[i].second;
        }
        
        return ans;
    }
};