class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
          return a[2]<b[2];
      }
      int findparent(vector<int>&parent,int x){
          if(parent[x]==x) return x;
          return parent[x]=findparent(parent,parent[x]);
      }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
      
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),cmp);
        sort(edgeList.begin(),edgeList.end(),cmp);

        vector<int> parent(n);
    
        for(int i=0;i<n;i++)parent[i]=i;

        int j=0;
        int elen=edgeList.size();
        for(auto &it: queries){
           
            while(j<elen && edgeList[j][2]<it[2]){
        
            int n1= findparent(parent,edgeList[j][0]);
            int n2=findparent(parent,edgeList[j][1]);         
            if(n1!=n2) {
              parent[n2]=n1;
             }
             j++;
            }
         
         if(findparent(parent,it[0])==findparent(parent,it[1])){
             ans[it[3]]=true;
         }
       
        }
        
      return ans;

       
    }
};