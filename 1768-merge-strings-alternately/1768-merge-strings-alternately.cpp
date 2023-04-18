class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int i=0;
        int j=0;
        int counter=0;
        while(i<word1.size() && j<word2.size()){
            if(counter%2==0){
                res=res+word1[i];
                i++;
            }
            else{
                res=res+word2[j];
                j++;
            }
            counter++;
        }
        while(i<word1.size()){
            res=res+word1[i];
            i++;
        }
        while(j<word2.size()){
            res=res+word2[j];
            j++;
        }
        return res;
    }
};