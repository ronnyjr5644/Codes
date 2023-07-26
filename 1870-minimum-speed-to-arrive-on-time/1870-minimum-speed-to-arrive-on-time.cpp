class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
          int n = dist.size();
        if (n - 1 >= hour) {
            return -1;
        }
        int i = 1;
        int j = 10000000;

        while (i <= j) {
            int mid = i + (j - i) / 2;
            double sum = 0.0;
            for (int k = 0; k < n - 1; k++) {
                sum += ceil(dist[k] / (double)(mid));
            }
            sum += (double)(dist[n - 1]) / mid;

            if (sum <= hour) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return j + 1;
    }
};