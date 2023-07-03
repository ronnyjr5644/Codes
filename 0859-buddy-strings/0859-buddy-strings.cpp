class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        if (A.size() != B.size()) 
            return false;
        
        // if strings are equal - check if there is a double to swap
        if (A == B) { 
            unordered_map<char, int> count;
            for (auto l:A){
                count[l]++;
                if (count[l] > 1)
                    return true;
            }
            return false;
        }
        
        // count differences between strings
        vector<int> diff;
        for (int i=0; i<A.size(); i++) {
            if (A[i] != B[i]) {
                diff.push_back(i);
                if (diff.size() > 2)
                    return false;
            }
        }
        // not exactly two differences
        if (diff.size() != 2)
            return false;
        
        // check if can be swapped
        if ((A[diff[0]] == B[diff[1]]) && (A[diff[1]] == B[diff[0]]))
            return true;
        
        return false;
    }
};