class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int>mp;
        int x=0;
        int y=0;
        mp[{x,y}]++;
        for(int i=0;i<path.size();i++){
            if(path[i]=='N'){
                y++;
                
            }
            if(path[i]=='E'){
                x++;
            }
            if(path[i]=='W'){
                x--;
            }
            if(path[i]=='S'){
                y--;
            }
            mp[{x,y}]++;
           // if(mp.count({x,y})>1){
           //     return true;
           // }
            
        }
        for(auto it:mp){
            if(it.second>1){
                return true;
            }
        }
        return false;
        // return false;
    }
};