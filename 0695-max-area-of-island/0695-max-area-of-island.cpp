class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid,int& temp){
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1 || grid[i][j]!=1){
            return;
        }
        temp++;
        grid[i][j]=2;
        dfs(i-1,j,grid,temp);
        dfs(i+1,j,grid,temp);
        dfs(i,j-1,grid,temp);
        dfs(i,j+1,grid,temp);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        bool flag=false;
        int n=grid.size();
        int m=grid[0].size();
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    flag=true;
                    int temp=0;
                    
               
                
                dfs(i,j,grid,temp);
                    if(temp>res){
                        
                        res=temp;
                    }
                }
            }
        }
        if(flag==false){
            return 0;
        }
        return res;
    }
};