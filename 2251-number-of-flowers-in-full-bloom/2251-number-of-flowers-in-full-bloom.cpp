class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
         vector<int> sortedArrivalTimes(people.begin(), people.end());
        sort(sortedArrivalTimes.begin(), sortedArrivalTimes.end());
        sort(flowers.begin(), flowers.end()) ;
        
        unordered_map<int, int> bloomCounts; 
        priority_queue<int, vector<int>, greater<int>> bloomEndTimes;
        int flowerIdx = 0 ;
        for(int personTime: sortedArrivalTimes){
            while(flowerIdx < flowers.size() && flowers[flowerIdx][0] <= personTime)
                bloomEndTimes.push(flowers[flowerIdx++][1]);
            while(!bloomEndTimes.empty() && bloomEndTimes.top() < personTime)
                bloomEndTimes.pop();
            bloomCounts[personTime] = bloomEndTimes.size();
        }

        vector<int> flowerCounts; 
        for(int arrivalTime: people)
            flowerCounts.push_back(bloomCounts[arrivalTime]);

        return flowerCounts; 
    
    }
};