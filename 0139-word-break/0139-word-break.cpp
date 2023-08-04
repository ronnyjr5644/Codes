class Solution {
public:
    class Trie{
      public:
        Trie *child[26];
        bool isEnd = false;
    };
    
    void insert(string &word, Trie* root){
        Trie *cur = root;
        for(auto &ch : word){
            if(!cur->child[ch-'a']) cur->child[ch-'a'] = new Trie();
            cur=cur->child[ch-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string &word, Trie* root){
        Trie *cur = root;
        for(auto &ch : word){
            if(!cur->child[ch-'a']) return false;
            cur=cur->child[ch-'a'];
        }
        return cur->isEnd;
    }
    
    int dp[305];
    bool solve(string &s, Trie *root, int n, int start){
        if(start==n) return true;
        if(dp[start]!=-1) return dp[start];
        string str = "";
        for(int i=start; i<n; ++i){
            str+=s[i];
            if(search(str,root)){
                if(solve(s,root,n,i+1)) return dp[start]= true;
            }
        }
        return dp[start] = false;
    }
    
    bool wordBreak(string &s, vector<string>& wordDict) {
        Trie *root = new Trie();
        for(auto &word : wordDict) insert(word,root);
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,root,n,0);
    }
};