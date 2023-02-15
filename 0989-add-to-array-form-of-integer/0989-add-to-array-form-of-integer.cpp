class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
       vector<int>ans;
        int carry=0;
    int n=num.size()-1;
    while(n>=0 || carry>0 || k!=0){
        if(k!=0){
            carry=carry+k%10;
            k=k/10;
        }
        if(n>=0){
            carry=carry+num[n];
            n--;
        }
        ans.push_back(carry%10);
        carry=carry/10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
        
        
        
        
        
        //         vector<int>res;
//         string x="";
//         for(int i=0;i<num.size();i++){
//             x=x+to_string(num[i]);
//         }
        
//         int a=stoi(x);
//         int c=a+k;
        
//         string y=to_string(c);
        
//         for(int i=0;i<y.size();i++){
//             res.push_back(y[i]-'0');
            
//         }
        
//         return res;
        // return res;
    }
};