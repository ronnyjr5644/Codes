
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>>res=img;
        for(int i=0;i<img.size();i++){
            for(int j=0;j<img[0].size();j++){
            
                int sum=0;
                int counter=0;
                for(int k=-1;k<2;k++){
                    for(int l=-1;l<2;l++){
                        int nrow=i+k;
                        int ncol=j+l;
                        if(nrow<0 or ncol<0 or nrow>=n or ncol>=m){
                            continue;
                        }
                        
                        sum+=img[nrow][ncol];
                        counter++;
                    }
                }
                res[i][j]=sum/counter;
            }
        }
        return res;
    }
};