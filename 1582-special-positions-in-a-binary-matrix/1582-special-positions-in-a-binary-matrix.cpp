class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int res=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1){
					int colSum = 0;
					int rowSum = 0;
					for(int r = 0; r < mat.size(); r++){
						colSum += mat[r][j];
					}
					for(int c = 0; c < mat[0].size(); c++){
						rowSum += mat[i][c];
					}
					if(colSum == 1 and rowSum == 1){
						res++;
					}
            }
        }
        }
            return res;
    }
};