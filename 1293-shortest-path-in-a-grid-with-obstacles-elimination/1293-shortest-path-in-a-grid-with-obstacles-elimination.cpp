class Solution {
public:
    int shortestPath(vector<vector<int>>& v, int k) {
        int n=v.size(), m=v[0].size();
	using cell=tuple<int, int, int, int>; // x,y,dist,remaining obst.
	queue<cell> q;
	vector<vector<int>> seen(n, vector<int>(m, -1)); // for every cell store remaining obst. 
	q.push({0,0,0,k});
	while (!q.empty()) {
		auto [x,y,d,remaining]=q.front();
		if(x==n-1 && y==m-1) return d;
		q.pop();
		if (v[x][y])
			if (--remaining<0) continue;
		if (seen[x][y]>=remaining)  // have seen this cell with more remaining
			continue;   
		seen[x][y]=remaining;
		++d;
		if (x<n-1) q.push({x+1,y,d,remaining});
		if (x>0)   q.push({x-1,y,d,remaining});
		if (y<m-1) q.push({x,y+1,d,remaining});
		if (y>0)   q.push({x,y-1,d,remaining});
	}
	return -1; 
    }
};