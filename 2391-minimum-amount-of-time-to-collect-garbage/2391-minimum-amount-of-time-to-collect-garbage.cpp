class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
         bool fg=false,fp=false,fm=false;
        int g=0,p=0,m=0;
        for(int i=garbage.size()-1;i>=0;i--)
        {
            for(char c:garbage[i])
            {
                if(c=='G'){g++; fg=true;}
                else if(c=='P'){ p++;fp=true;}
                else if(c=='M') {m++; fm=true;}
            }
            if (i!=0 && fg==true)g+=travel[i-1];
            if (i!=0 && fp==true)p+=travel[i-1];
            if (i!=0 && fm==true)m+=travel[i-1];
        }
        return g+m+p;
    }
};