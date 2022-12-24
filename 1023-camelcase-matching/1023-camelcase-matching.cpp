class Solution {
public:
    bool solve(string s, string pat) {
		int i = 0, j = 0;   
		while(i < s.size() && j < pat.size()) {
			if(s[i] == pat[j]){ 
				i++, j++;
            }
			else if(s[i] >= 'A' && s[i] <= 'Z'){
				return false;
            }
			else{
				i++;
            }
		}
		if(j<pat.size()){    
			return false;
        }
		while(i < s.size()) {    
			if(s[i] >= 'A' && s[i] <= 'Z'){
				return false;
            }
			i++;
		}
		return true;
	}
	vector<bool> camelMatch(vector<string>& queries, string pattern) {
		int n= queries.size();
		vector<bool>ans;
		for(int i=0;i<n;i++) {
			if(solve(queries[i],pattern)==1)
				ans.push_back(true);
			else
				ans.push_back(false);
		}
		return ans;
	}
};