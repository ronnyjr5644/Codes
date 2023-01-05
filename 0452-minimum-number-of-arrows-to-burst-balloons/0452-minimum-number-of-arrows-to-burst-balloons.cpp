class Solution {
public:
  static bool comp(vector<int>& x, vector<int>& y){
		return x[1] < y[1];
	}
	int findMinArrowShots(vector<vector<int>>& points) {
		if(points.size() == 1){
			return 1;
		}
		sort(points.begin(), points.end(), comp);
		int res = 1;
		int prev = points[0][1];
		for(int i = 1; i < points.size(); i++){
			if(prev < points[i][0]){
				res++;
				prev = points[i][1];
			}
		}
		return res;
    }
};