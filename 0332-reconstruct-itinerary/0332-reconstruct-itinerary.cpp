class Solution {
public:
      unordered_map<string, priority_queue<string, vector<string>, greater<string>>>fly; 
    void build_graph(vector<vector<string>>& tickets){
        for(auto& edge: tickets){
            string From=edge[0], To=edge[1];
            fly[From].push(To);
        }
    }
    deque<string> ans;
    void dfs(string From){
        while(!fly[From].empty()){
            string To=fly[From].top();
            fly[From].pop();
            dfs(To);
        }
        ans.push_front(From);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        build_graph(tickets);
        dfs("JFK");
        return vector<string>(ans.begin(), ans.end());
    }
};