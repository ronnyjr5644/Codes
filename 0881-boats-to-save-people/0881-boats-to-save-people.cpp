class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;

        sort(people.begin(), people.end()); 
        int lightPtr = 0;
        for(int heavyPtr = people.size() - 1; heavyPtr >= 0 && lightPtr <= heavyPtr; heavyPtr--) { 
            if(people[lightPtr] + people[heavyPtr] <= limit) lightPtr++;
            boats++;
        }

        return boats;
    }
};