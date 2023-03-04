class Solution {
public:
       
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size()){
            return -1;
        }
        int n=needle.size();
        for(int i=0;i<=haystack.size()-n;i++){
            string str=haystack.substr(i,needle.size());
            if(str==needle){
                return i;
            }    
        }
        return -1;
    }
};