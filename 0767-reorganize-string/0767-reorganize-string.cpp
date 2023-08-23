class Solution {
public:
    string reorganizeString(string s) {
         unordered_map<char,int> fre;
        int n = s.length();
        for(int i=0;i<n;i++){
            fre[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto a:fre){
            pq.push({a.second,a.first});
        }
        string ans = "";
        while(pq.size()>1){
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            ans += a.second;
            ans+=b.second;
            a.first--;
            b.first--;
            if(a.first!=0){
                pq.push({a.first,a.second});
            }
            if(b.first!=0){
                pq.push({b.first,b.second});
            }
        }
        if(pq.empty()) return ans;
        if(pq.top().first>1) return "";
        ans += pq.top().second;

        return ans;
    }
};