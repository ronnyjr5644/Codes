class Solution {
public:
    string minWindow(string s, string t)
    {
       unordered_map<char,int>om;
       for(int i=0; i<t.size(); i++)
       {
           om[t[i]]++;
       }
       int cnt=t.size();
       int j=0;
       int x=INT_MAX,y=0;
       for(int i=0; i<s.size(); i++)
       {
           if(om.find(s[i])!=om.end() && om[s[i]]>0)
           {
               cnt--;
           }
           om[s[i]]--;
           while(cnt==0)
           {
               if(i-j+1<x)
               {
                   x=i-j+1;
                   y=j;
               }
               om[s[j]]++;
               if(om[s[j]]>0)
               {
                   cnt++;
               }
               j++;
           }
       }
       if(x==INT_MAX)
       {
           return "";
       }
       return s.substr(y,x);
    }
};