class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0;
        int n=words.size();
        vector<string>ans;
        while(i<n){
            int len=words[i].length();
            int j=i+1;
            while(j<n && len+words[j].length()+j-i<=maxWidth){
                len+=words[j].length();
                j++;
            }

            int nword=j-i;
            int nspace=maxWidth-len;

            string ss="";

            if(nword==1 || j==n){
                ss=words[i];
                for(int k=i+1;k<j;k++){
                    ss=ss+' '+words[k];
                }
                ss=ss+string(maxWidth-ss.size(),' ');
            }
            else{
                int ms=nspace/(nword-1);
                int es=nspace%(nword-1);

                ss=words[i];
                for(int k=i+1;k<j;k++){
                    ss=ss+string(ms,' ');
                    if(es>0){
                        es--;
                        ss+=' ';
                    }
                    ss+=words[k];
                }
            }
            i=j;
            ans.push_back(ss);
            
        }
        return ans;
    }
};