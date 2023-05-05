class Solution {
public:
     bool isVowel(char c){
        char t = tolower(c);
        return t == 'a' or t == 'e' or t=='i' or t=='o' or t=='u';
    }
    
    int maxVowels(string s, int k) {
        int n = s.size();
        int start = 0;
        int end = 0;

        int ans = 0;  
        int temp = 0;  

       
        while(end < n){
            
            if(isVowel(s[end])){
               temp++;
           }
          
          
           if(end-start == k ){
               if(isVowel(s[start])){
                   temp--;  
               }
               start++;  
           }
           
           ans = max(ans, temp); 
           end++; 
        }
        
        return ans; 
    }
};