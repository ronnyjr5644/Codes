class Solution {
public:
//     string smallestEquivalentString(string s1, string s2, string baseStr) {
//      map<char,set<char>>mp;
//      for(int i=0;i<s1.size();i++)
//      {
//        mp[s1[i]].insert(s2[i]);
//        mp[s2[i]].insert(s1[i]);
//      } 
//      for(auto it=mp.begin();it!=mp.end();it++)  //from front
//      {
//          for(auto itin:it->second)
//          {
//            for(auto itt:mp[itin])
//                mp[it->first].insert(itt);
//          }
//      }
//       for(auto it=mp.rbegin();it!=mp.rend();it++) //from back
//      {
//          for(auto itin:it->second)
//          {
//            for(auto itt:mp[itin])
//                mp[it->first].insert(itt);
//          }
//      }

//      for(int i=0;i<baseStr.size();i++)
//      {
//          char mini='z';
//          for(int j=0;j<mp[baseStr[i]].size();j++)
//          {
//          for(auto it:mp[baseStr[i]])
//               mini=min(mini,it);
//          }
//          baseStr[i]=min(mini,baseStr[i]);
//      }
//      return baseStr;
int par[26];
    
    int find(int x){
        if(par[x]==-1) return x;
        return par[x]=find(par[x]);
    }
    
    void Union(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x != y) 
            par[max(x, y)] = min(x, y); 
    }
	
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        memset(par, -1, sizeof(par));
        
        for (auto i = 0; i < s1.size(); ++i) 
            Union(s1[i] - 'a', s2[i] - 'a');
        
        for(auto i=0;i<baseStr.size();i++) 
            baseStr[i]=find(baseStr[i]-'a')+'a';

        return baseStr;
    
    }
};