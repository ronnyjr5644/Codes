class Solution {
public:
    string largestGoodInteger(string num) {
       
        vector<string>v = {"999","888","777","666","555","444","333","222","111","000"};
        for(auto x : v)
        {
            if(num.find(x) != -1)
            return x;
        }
        return "";
    }
};