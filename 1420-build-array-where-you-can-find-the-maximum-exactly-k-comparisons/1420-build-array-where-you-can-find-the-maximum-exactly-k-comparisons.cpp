class Solution {
public:
      int MOD = 1e9 + 7;
    int memo[51][101][51];
    int numOfArrays(int n, int m, int k) {
        for(int i = 0; i < 51; i++)
            for(int j = 0; j < 101; j++)
                for(int l = 0; l < 51; l++)
                    memo[i][j][l] = -1;
        return dp(0, 0, n, m, k) % MOD;
    }
    int dp(int idx, int maxN, int& n, int& m, int k){
        if(idx == n)
            return k == 0;
        if(k < 0)
            return 0;
        if(memo[idx][maxN][k] != -1)
            return memo[idx][maxN][k];
        int res = 0;
        for(int i = 1; i <= m; i++)
            res += dp(idx + 1, max(maxN, i), n, m, k - (i > maxN)) % MOD, res %= MOD;
        return memo[idx][maxN][k] = res % MOD;
    }
};