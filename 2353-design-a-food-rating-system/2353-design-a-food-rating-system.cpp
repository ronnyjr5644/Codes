
#define p pair<int,string> 
struct Comp{
    bool operator()(p a,p b){
        return a.first==b.first? a.second>b.second:a.first<b.first;
    }  
};
class FoodRatings {
public:
    map<string,priority_queue<p,vector<p>,Comp>>mp; 
    unordered_map<string,pair<int,string>>curr; 
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            mp[cuisines[i]].push({ratings[i],foods[i]});
            curr[foods[i]]={ratings[i],cuisines[i]};
        }
    }
    void changeRating(string food, int r) {
        string c=curr[food].second;
        curr[food]={r,c};
        mp[c].push({r,food});
    }
    string highestRated(string cuisine) {
        while(true){
            string food=mp[cuisine].top().second;
            int r=mp[cuisine].top().first;
            if(curr[food].first==r){
                break;
            }
            mp[cuisine].pop();
        }
        return mp[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */