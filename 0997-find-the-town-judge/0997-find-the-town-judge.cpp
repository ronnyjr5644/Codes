class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
//         set<int>judge;
//         set<int>town;
//         if(trust.size()==1){
//             return trust[0][1];
//         }
//         for(int i=0;i<trust.size();i++){
//             town.insert(trust[i][0]);
//             judge.insert(trust[i][1]);
//         }
//         int ans;
//         int count=0;
//         for(auto &it:judge){
//             if(town.find(it)==town.end()){
//                 ans=it;
//                 count++;
//             }
//         }
      
//         if(town.size()==count){
//             return ans;
//         }
//         else{
//         return -1;
//         }
      	if(trust.empty() && n==1){
            return 1;
        }
		vector<int> out(n+1,0);
		vector<int> in(n+1,0);
		for(auto edge : trust){
            out[edge[0]]++;
            in[edge[1]]++;
        }
		for(int i=0;i<=n;i++){
            if(out[i]==0 && in[i]==n-1)
                return i;
        }
        return -1;  
    }
};
