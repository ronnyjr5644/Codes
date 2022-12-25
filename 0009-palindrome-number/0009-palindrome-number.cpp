class Solution {
public:
    bool ispal(string y,int l,int r){
        if(y.size()==0 || l<0 || r<0){
            return 0;
        }
        if(l>=r){
            return 1;
        }
        if(y[l]==y[r]){
           
            return ispal(y,l+1,r-1);
        }
        return 0;
    }
    bool isPalindrome(int x) {
       
        int l=0;
       
        string y=to_string(x);
         int r=y.size()-1;
         return ispal(y,l,r);
        
    }
};