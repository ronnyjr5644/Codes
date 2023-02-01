class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        if(str1+str2!=str2+str1){
            return "";
        }
        int i=0;
        int j=0;
        string res="";
        int x=gcd(n,m);
        while(i<x){
            if(str1[i]!=str2[i]){
                break;
            }
            else if( str1[i]==str2[i]){
                res=res+str1[i];
               i++;
                
            }
        }
        return res;
    }
};