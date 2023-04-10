class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int n= s.length();
        for (int i=0;i<n;i++){    
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty()){
                    return false;
                }
                else if(s[i] == ')' && st.top() != '('){
                    return false;
                }
                else if(s[i] == '}' && st.top() != '{'){
                    return false;
                }  
                else if(s[i] == ']' && st.top() != '['){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};