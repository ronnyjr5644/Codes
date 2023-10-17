class Solution {
public:
   bool check(vector<int> &leftChild,vector<int> &rightChild,int index)
    {
        int N = leftChild.size();
        vector<int> visited(N,0);
        //visited[index] = 1;
        queue<int> qu;
        qu.push(index);

        bool ans = true;

        while(!qu.empty())
        {
            int root = qu.front();
            qu.pop();
            if(visited[root]==1)
            {
                ans = false;
                break;
            }
            visited[root] = 1;

            int left = leftChild[root];
            int right = rightChild[root];

            if(left!=-1)
            {
                qu.push(left);
            }

            if(right!=-1)
            {
                qu.push(right);
            }
        }

        if(ans==false)
        {
            return false;
        }

        for(int i=0;i<N;i++)
        {
            if(visited[i]==0)
            {
                ans = false;
                break;
            }
        }

        return ans;    
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n,-1);
        for(int i=0;i<n;i++)
        {
            int left = leftChild[i];
            int right = rightChild[i];
            if(left!=-1)
            parent[left] = i;
            if(right!=-1)
            parent[right] = i;
        }

        int count  = 0;
        int index;

        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
            {
                count++;
                index = i;
            }
        }
        if(count!=1)
        return false;

        bool ans = check(leftChild,rightChild,index);
        return ans;
    }
};