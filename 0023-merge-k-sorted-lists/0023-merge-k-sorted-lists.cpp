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
   ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.empty()) return NULL;
        
        // MAX heap
        priority_queue<pair<int, ListNode*>> pq; // (value, Node address)
        int n=lists.size();
        
        for(int i=0;i<n;i++)
        {
            ListNode *p = lists[i];
            while(p)
            {
                pq.push({-p->val, p}); // acts as min heap
                p = p->next;
            }
        }
                
        ListNode* head=NULL;
        ListNode* last=NULL;
        
        if(pq.empty()) return head;
        
        head=pq.top().second;
        last=pq.top().second;
        pq.pop();
        
        
        while(!pq.empty())
        {
            last->next = pq.top().second;
            last = pq.top().second;
            pq.pop();
            
        }
        last->next=NULL;
        
        return head;
        
    }
};