class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         int n1=s1.size();
        int n2=s2.size();
        if(n1>n2){
            return false;
        }
        vector<int>num1(26,0);
        vector<int>num2(26,0);
        for(char it:s1){
            num1[it-'a']++;
        }
        for(int i=0;i<n2;i++){
            num2[s2[i]-'a']++;
            if(i>=n1){
                num2[s2[i-n1]-'a']--;
            }
            if(num1==num2){
                return true;
            }
        }
        return false;
        //brute force approach
        // string x=s1;
        //   if (s2.find(x) != std::string::npos) {
        //             return true;
        //     }
        // next_permutation(x.begin(),x.end());
        // while(1){
        //     if (s2.find(x) != std::string::npos) {
        //             return true;
        //     }
        //     if(s1==x){
        //         break;
        //     }
        //     next_permutation(x.begin(),x.end());
        // }
        // return false;
    }
};