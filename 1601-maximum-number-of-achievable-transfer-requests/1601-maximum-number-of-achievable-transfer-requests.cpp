class Solution {
public:
    int ans = 0;
    vector<int> transfer;
    void helper(int curr, int n, vector<vector<int>>& requests, int cnt) {
        if (curr == requests.size()) {
            if (all_of(transfer.begin(), transfer.end(), [](int element) { return element == 0; }))
                ans = max(ans, cnt);
            return;
        }

        int res = 0;
        helper(curr + 1, n, requests, cnt);
        
        transfer[requests[curr][0]]++;
        transfer[requests[curr][1]]--;
        helper(curr + 1, n, requests, cnt + 1);
        transfer[requests[curr][0]]--;
        transfer[requests[curr][1]]++;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        transfer.resize(n);
        helper(0, n, requests, 0); 
        return ans;
    }
};