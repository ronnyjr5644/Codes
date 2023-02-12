//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
     bool isPrime(int n){
        if(n==1 or n<=0) return false;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }

    Node *primeList(Node *head){
       Node* root=head;
        while(head!=NULL){
            int temp = head->val;
            
            if(isPrime(temp)){
                head = head->next;
                continue;
            }
            else{
                int temp2 = temp;
                while(!isPrime(temp) and !isPrime(temp2)){
                    temp++;
                    temp2--;
                }
                
                if(isPrime(temp) and isPrime(temp2)){
                    head->val = min(temp,temp2);
                }
                else if(isPrime(temp2)){
                    head->val = temp2;
                }
                else{
                    head->val = temp;
                }
                
                head = head->next;
            }
        }
        return root;  
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends