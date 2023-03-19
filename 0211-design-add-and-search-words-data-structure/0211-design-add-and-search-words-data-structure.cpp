struct node {
    node* next[26];
    bool hasWord;
    
    node() {
        for(int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        hasWord = false;
    }
};
class WordDictionary {
public:
    node* root = new node();

    void addWord(const string& word) {
        node* curV = root;
        for(int i = 0; i < word.length(); i++) {
            int curIndex = word[i] - 'a';

			if(!curV->next[curIndex]) {
                curV->next[curIndex] = new node();
            }
            
            curV = curV->next[curIndex];
        }
        curV->hasWord = true;
    }
    
    bool search(const string& word) {
        return searchHelper(word, 0, root);
    }
    
    bool searchHelper(const string& word, int index, node* curV) {
        // BASE CASE
        if (index == word.length()) {
            return curV->hasWord;
        }

        
        char curChar = word[index];

        // when char is defiend
        if (curChar != '.') {
            if (curV->next[curChar - 'a'])
                return searchHelper(word, index + 1, curV->next[curChar - 'a']);
            return false;
        }
        
        // when char is undefiend
        for (int i = 0; i < 26; i++) {
            if (curV->next[i] != nullptr) {
                if (searchHelper(word, index + 1, curV->next[i]))
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */