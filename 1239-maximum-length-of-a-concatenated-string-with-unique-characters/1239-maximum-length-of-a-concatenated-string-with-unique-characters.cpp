class Solution {
public:
   bool hasDuplicate(string &s1,string &s2){
        vector<int>freq(26,0);
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>1){
                return true;
            }
        }
        for(int i=0;i<s2.size();i++){
            freq[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>1){
                return true;
            }
        }
        return false;
    }
    int solve(vector<string>&arr,int idx,string temp){
        int n=arr.size();
        if(idx>=n){
            return temp.size();
        }
        int include=0,exclude=0;
        if(hasDuplicate(arr[idx],temp)){
            exclude=solve(arr,idx+1,temp);
        }
        else{
            exclude=solve(arr,idx+1,temp);
            include=solve(arr,idx+1,temp+arr[idx]);
        }
        return max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
       string temp;
       int ans=solve(arr,0,temp); 
       return ans;
    }
};