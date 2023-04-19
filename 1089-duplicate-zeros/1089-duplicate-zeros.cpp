class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int>res;
        for(int i=0;i<arr.size();i++){
            
            if(arr[i]==0){
                res.push_back(arr[i]);
                res.push_back(0);
            }
            else{
                res.push_back(arr[i]);
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=res[i];
        }
    }
};