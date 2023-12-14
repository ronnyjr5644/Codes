class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
    vector<int> r_one(m), c_one(n), r_zero(m), c_zero(n);
     
    for(int i = 0;i < m; i++)
        for(int j = 0;j < n; ++j)
            if(A[i][j])
                r_one[i]++ , c_one[j]++;
            else
                r_zero[i]++, c_zero[j]++;
    
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            A[i][j] = r_one[i] + c_one[j] - r_zero[i] - c_zero[j];
    
    return A;
}
};