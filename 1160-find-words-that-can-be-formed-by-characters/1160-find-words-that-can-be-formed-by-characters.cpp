class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> count(26);
    int total = 0;
    for (auto ch : chars) ++count[ch - 'a'];

    for (auto& word : words) {
        vector<int> wCount(26);
        bool canConstruct = true;
        for (auto ch : word) {
            auto index = ch - 'a';
            if (++wCount[index] > count[index]) {
                canConstruct = false;
                break;
            }
        }
        if (canConstruct) total += word.size();
    }
    return total;
    }
};