class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u' or ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U') return 1;
        return 0;
    }
    
    string sortVowels(string s) {
        vector<char> vowels;
        for(int i=0; i < s.size(); i++){
            if(isVowel(s[i])) vowels.push_back(s[i]);
        }
        sort(vowels.begin(), vowels.end());
        int index = 0, vowelSize = vowels.size();
        for(int i=0; i < s.size(); i++){
            if(vowelSize==index) break;
            if(isVowel(s[i])) s[i]=vowels[index++];
        }
        return s;
    }
};