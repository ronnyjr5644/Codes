class Solution {
public:
    struct compare{
        bool operator()(vector<int> &a,vector<int> &b){
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]>b[0];
        }
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<vector<int>,vector<vector<int>>,compare> q;
        for(int i=0;i<profits.size();i++){
            q.push({capital[i],profits[i]});
        }
        priority_queue<int> pq;
        while(!q.empty()&&k>0){
            while(!q.empty()&&q.top()[0]<=w){
                pq.push(q.top()[1]);
                q.pop();
            }
            if(pq.empty())
                return w;
            w+=pq.top();
            pq.pop();
            k--;
        }
        while(k>0&&!pq.empty()){
            w+=pq.top();
            k--;
            pq.pop();
        }
        return w;
    }
};