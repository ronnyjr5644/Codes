class Solution {
public:
    void topologicalSort(vector<int>adj[],vector<bool>& visited, stack<int>& st, int node){
        visited[node]=true;
        for(auto it: adj[node]){
            if(!visited[it]) topologicalSort(adj,visited,st,it); 
        }
        st.push(node); 
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){ 
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]); 
        }
        vector<bool>visited(numCourses, false);
        stack<int> st;
        unordered_map<int,int> position;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]) topologicalSort(adj,visited,st,i); 
        }
        vector<int> ans;
        int idx=0;
        while(!st.empty()){
            ans.push_back(st.top()); 
            position[st.top()]=idx;
            idx++;
            st.pop();
        }
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
                if(position[i]>position[it]) return {}; 
            }
        }
        return ans;
    
    }
};