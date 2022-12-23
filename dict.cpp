class Solution
{
    struct TrieNode{
    bool isEnd;
    TrieNode*children[26];
    int count;
    TrieNode(){
        isEnd=false;
        count=0;
        for(int i=0;i<26;i++)
            children[i] = nullptr;
    }
};
    public:
    void insert(TrieNode*root,string word){
        TrieNode*curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(curr->children[idx]==NULL){
                curr->children[idx]=new TrieNode();
            }
            curr->count++;
            curr=curr->children[idx];
        }
        curr->count++;
        curr->isEnd=true;
    }
    string search(TrieNode *root,string &word){
        TrieNode*curr=root;
        string ans="";
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(curr->children[idx]->count==1){
                ans=ans+word[i];
                break;
            }
            ans=ans+word[i];
            curr=curr->children[idx];
        }
        return ans;
    }
    vector<string> findPrefixes(string arr[], int n){
         TrieNode* root=new TrieNode();
         vector<string>res;
         for(int i=0;i<n;i++){
             insert(root,arr[i]);
         }
         for(int i=0;i<n;i++){
             string x=search(root,arr[i]);
             res.push_back(x);
         }
         return res;
    }
    
};
