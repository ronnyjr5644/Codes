//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

    void mark_parent(Node* root, unordered_map<Node*,Node*> &parent_track, int target,Node* &tgt)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node*curr = q.front();
            q.pop();
            if(curr->data == target)
                tgt = curr;
            if(curr->left != NULL)
            {
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right != NULL)
            {
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
       
        unordered_map<Node*,Node*> parent_track;
        Node* tgt = NULL;
        mark_parent(root,parent_track,target,tgt);  
        
        unordered_map<Node*,bool> visited;
        queue<Node*> q;
        q.push(tgt);
        visited[tgt] = true;
        int curr_level = 0;
        while(!q.empty())
        {
            int size = q.size();
            if(curr_level++ == k)
                break;
            //curr_level++;
            for(int i=0;i<size;i++)
            {
                Node* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(parent_track[temp] && !visited[parent_track[temp]])
                {
                    q.push(parent_track[temp]);
                    visited[parent_track[temp]] = true;
                }
            }
        }
        
        vector<int> result;
        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            result.push_back(curr->data);
        }
        sort(result.begin(),result.end());
        return result;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends