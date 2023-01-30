//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/
void insert(Node** root,int item){
    Node* temp=new Node(item);
    Node* ptr;
    if(*root==NULL){
        *root=temp;
    }
    else{
        ptr=*root;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
Node* findIntersection(Node* head1, Node* head2)
{
   vector<int>h1;
   vector<int>h2;
   
   
   Node* a=head1;
   Node* b=head2;
   while(a!=NULL){
       h1.push_back(a->data);
       a=a->next;
   }
   while(b!=NULL){
       h2.push_back(b->data);
       b=b->next;
   }
   vector<int>final;
   set_intersection(h1.begin(),h1.end(),h2.begin(),h2.end(),back_inserter(final)); 
   
//   map<int,int>mp;
//   for(int i=0;i<h1.size();i++){
//       mp[h1[i]]++;
//   }
//   for(int i=0;i<h2.size();i++){
//       mp[h2[i]]++;
//   }
//   vector<int>final;
//   for(auto it:mp){
//       if(it.second>=2){
//           final.push_back(it.first);
//       }
//   }
   Node*root=NULL;
   for(int i=0;i<final.size();i++){
       insert(&root,final[i]);
   }
   return root;
//   b=head2;
//   int i=0;
//   while(i<final.size()){
       
        
           
       
//       b->data=final[i];
//       i++;
//       b=b->next;
       
       
//   }
//       b->next=NULL;
//   return head2;
}