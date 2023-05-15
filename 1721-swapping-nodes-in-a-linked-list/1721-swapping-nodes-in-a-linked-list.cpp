/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>temp;
        ListNode* x=head;
        while(x!=NULL){
            temp.push_back(x->val);
            x=x->next;
        }
        x=head;
        int l=temp[k-1];
        int n=temp.size();
        temp[k-1]=temp[n-k];
        temp[n-k]=l;
            
        for(int i=0;i<n;i++){
            x->val=temp[i];
            x=x->next;
        }
        return head;
        
    }
};