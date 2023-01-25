class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
		queue<int> q1, q2;
		int ans = n;
		if (node1 == node2)
			return node1; 
		q1.push(node1);
		q2.push(node2);
		vector<bool> vis1(n, 0), vis2(n, 0); 
		vis1[node1] = 1;
		vis2[node2] = 1;
		while (q1.size() || q2.size())
		{
			int x = -1, y = -1;
			if (q1.size())
			{
				x = edges[q1.front()];
				q1.pop();
			}
			if (q2.size())
			{
				y = edges[q2.front()];
				q2.pop();
			}
			if (x != -1 and x == y)
				ans = min(ans, x); 
			if (x != -1)
			{
				if (vis2[x])
					ans = min(ans, x); 
				if (!vis1[x])
				{
					vis1[x] = 1;
					q1.push(x);
				}
			}
			if (y != -1)
			{
				if (vis1[y])
					ans = min(ans, y); 
				if (!vis2[y])
				{
					vis2[y] = 1;
					q2.push(y);
				}
			}
			if (ans != n)
				return ans;
		}
		return -1;
    }
};