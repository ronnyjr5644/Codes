//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
struct Trie {
  bool isTerminal;
  Trie* children[26];
  Trie() {
    isTerminal = false;
    memset(children, 0, sizeof(children));
  }
};
    Trie * root = new Trie();
    string longestString(vector<string> &words){
       for(auto i : words)
       Insert(i);
       string ans ;
       queue<pair<Trie *, string> > q;
       q.push({root, ""});
       while(!q.empty()){
           int size = q.size();
           ans = q.front().second;
           for(int k =  0 ; k<size ; k++){
               Trie * front  = q.front().first;
               string s = q.front().second;               for(int i = 0 ; i<26 ; i++){
                   if(front->children[i] && front->children[i]->isTerminal){
                       s.push_back('a'+i);
                       q.push({front->children[i], s});
                       s.pop_back();
                   }
               }
               
               q.pop();
           }
       }    
       return ans;
    }
     void Insert(string &word){
        Trie * temp = root;
        for(int i = 0 ; i<word.length() ; i++){
           if(temp->children[word[i]-'a'] == NULL){
               temp->children[word[i]-'a'] = new Trie();
           }
           
           temp = temp->children[word[i]-'a'] ;
        }
        temp->isTerminal = true;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends