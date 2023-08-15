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
    ListNode* partition(ListNode* head, int x) {
      ListNode *lesser = NULL;
        ListNode *greater = NULL;
        ListNode *startLesser = NULL;
        ListNode *startGreater = NULL;

        ListNode *prev;

        while(head != NULL){
            prev = head;
            head = head->next;
            prev->next = NULL;

            if(prev->val < x){
                if(lesser == NULL){
                    lesser = prev;
                    startLesser = lesser;
                }
                else{
                    lesser->next = prev;
                    lesser = lesser->next;
                }
            }

            else{
                if(greater == NULL){
                    greater = prev;
                    startGreater = greater;
                }
                else{
                    greater->next = prev;
                    greater = greater->next;
                }
            }

        }

        if(!startLesser) return startGreater;
        if(!startGreater) return startLesser;
        lesser->next = startGreater;

        return startLesser;

    }
};