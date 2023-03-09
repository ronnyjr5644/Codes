/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         unordered_set<ListNode*> hashSet;
        while(head!=NULL){
            if(hashSet.find(head)!=hashSet.end()) return head;
            hashSet.insert(head);
            head=head->next;
        }
        return NULL;
    }
};