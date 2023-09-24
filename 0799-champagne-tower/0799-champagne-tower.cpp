class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> v(102, vector<double> (102, 0.0));
        v[0][0] = poured;
        for(int i = 0; i <= query_row; i++){
            for(int j = 0; j <= i; j++){
                if(v[i][j] >= 1){
                    v[i + 1][j] += (double)((v[i][j] - 1) / 2);
                    v[i + 1][j + 1] += (double)((v[i][j] - 1) / 2);
                    v[i][j] = 1;
                }
            }
        }
        return v[query_row][query_glass];
    }
};