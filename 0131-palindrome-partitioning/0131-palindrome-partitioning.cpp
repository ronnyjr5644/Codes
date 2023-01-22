class Solution {
public:
    bool ispal(int start,int end,string& s){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(int i,int n,string s,vector<string>&temp,vector<vector<string>>&res){
        if(i==n){
            res.push_back(temp);
            return;
        }
        for(int j=i;j<n;j++){
            if(s[j]==s[i] && ispal(i,j,s)){
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,n,s,temp,res);
				temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        int n=s.size();
        solve(0,n,s,temp,res);
        return res;
    }
};