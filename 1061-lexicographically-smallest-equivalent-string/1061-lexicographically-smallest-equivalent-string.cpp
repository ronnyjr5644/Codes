class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
     map<char,set<char>>mp;
     for(int i=0;i<s1.size();i++)
     {
       mp[s1[i]].insert(s2[i]);
       mp[s2[i]].insert(s1[i]);
     } 
     for(auto it=mp.begin();it!=mp.end();it++)  //from front
     {
         for(auto itin:it->second)
         {
           for(auto itt:mp[itin])
               mp[it->first].insert(itt);
         }
     }
      for(auto it=mp.rbegin();it!=mp.rend();it++) //from back
     {
         for(auto itin:it->second)
         {
           for(auto itt:mp[itin])
               mp[it->first].insert(itt);
         }
     }

     for(int i=0;i<baseStr.size();i++)
     {
         char mini='z';
         for(int j=0;j<mp[baseStr[i]].size();j++)
         {
         for(auto it:mp[baseStr[i]])
              mini=min(mini,it);
         }
         baseStr[i]=min(mini,baseStr[i]);
     }
     return baseStr;
    }
};