class Solution {
public:
    int minDeletions(string s) {
           vector<int> freq(26, 0);
        for(char c: s)
            freq[c-'a']++;
        priority_queue<int> pq;
        for(int f: freq)
            if (f>0) pq.push(f);

        int upper=pq.top();
     //   cout<<upper<<endl;
        pq.pop();
        int ans=0;
        while(!pq.empty() && upper>=1){
            int top=pq.top();
            pq.pop();
            int del=top+1-upper;
            if (del<0) upper=top;
            else{
                ans+=del;
                upper--;
            }
        //    cout<<upper<<endl;
        }
        while(!pq.empty()){
            int top=pq.top();
            pq.pop();
            ans+=top;
        }
        return ans;
    }
};