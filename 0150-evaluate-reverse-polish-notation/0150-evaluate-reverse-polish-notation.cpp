class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>number;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){

                long long int y=number.top();
                number.pop();
                long long int x=number.top();
                number.pop();
                if(tokens[i]=="+" ){
                    x=x+y;
                }
                if(tokens[i]=="-" ){
                    x=x-y;
                }
                if(tokens[i]=="*" ){
                    x=x*y;
                }
                if(tokens[i]=="/" ){
                    x=x/y;
                }
            
             number.push(x);
            }
            else{
                number.push(stoi(tokens[i]));
            }
        }
        return number.top();
    }
};