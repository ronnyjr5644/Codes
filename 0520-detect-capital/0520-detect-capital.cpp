class Solution {
public:
    bool detectCapitalUse(string word) {
        string a=word;
        string b=word;
        string c=word;
        for(int i=0;i<word.size();i++){
            a[i]=tolower(a[i]);
        }
       
        if(a==word){
            return true;
        }
        for(int i=0;i<word.size();i++){
            b[i]=toupper(b[i]);
        }
        
        
        if(b==word){
            return true;
        }
        int flag=0;
        int flag1=0;
        if(word[0]>='A' && word[0]<='Z'){
            flag=1;
            for(int i=1;i<word.size();i++){
                if(word[i]>='A'&& word[i]<='Z'){
                    flag1=1;
                }
            }
        }
        if(flag==1 && flag1==0){
            
            return true;
        }
        return false;
    }
};