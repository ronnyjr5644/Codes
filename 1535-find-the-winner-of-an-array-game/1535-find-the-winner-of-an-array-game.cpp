class Solution {
public:
      int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        int maxi = *max_element(arr.begin(), arr.end());

        if(k >= n){
            return maxi;
        }


        unordered_map<int, int> mp;
        deque<int> dq;

        for(int i = 0; i < n; i++){
            dq.push_back(arr[i]);
        }
        
        int ans = maxi;

        while(true){
            int first = dq.front();
            dq.pop_front();
            int second = dq.front();
            dq.pop_front();

            if(first > second){
                mp[first]++;
                dq.push_front(first);
                dq.push_back(second);
                if(mp[first] == k){
                    ans = first;
                    break;
                }
            }
            else if(first < second){
                mp[second]++;
                dq.push_front(second);
                dq.push_back(first);
                if(mp[second] == k){
                    ans = second;
                    break;
                }
            }
        }

        return ans;
      }
};