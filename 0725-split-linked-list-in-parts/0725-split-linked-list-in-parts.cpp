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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
         int n=0;
        auto curr=head;
        while(curr){
            curr=curr->next;
            n++;
        }
        int p=n/k;
        int q=n%k;
        vector<ListNode *> ans;
        int sz=0;
        curr=head;
        while(curr){
            if(!sz) ans.push_back(curr);
            sz++;
            int x=p+(q>0);
            if(sz==x){
                sz=0;
                q--;
                auto next=curr->next;
                curr->next=NULL;
                curr=next;
            }
            else curr=curr->next;
        }
        while(ans.size()<k) ans.push_back(NULL);
        return ans;
    }
};