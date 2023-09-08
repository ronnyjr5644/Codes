class Solution {
public:
    vector<vector<int>> generate(int numRows) {
          vector<vector<int>>ans;
        map<pair<int,int>,int>mpp;
        for(int row=0;row<numRows;row++)
        {
            vector<int>temp;
            for(int col=0;col<=row;col++)
            {
                if(col==0 || col==row)
                {
                    temp.push_back(1);
                    mpp[make_pair(row,col)]=1;
                }
                else
                {
                    mpp[make_pair(row,col)]=mpp[make_pair(row-1,col-1)]+mpp[make_pair(row-1,col)];
                    temp.push_back(mpp[make_pair(row,col)]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};