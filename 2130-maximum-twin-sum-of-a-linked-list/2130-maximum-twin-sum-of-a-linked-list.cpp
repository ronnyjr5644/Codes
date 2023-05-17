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
    int pairSum(ListNode* head) {
        vector<int>temp;
        ListNode* x=head;
        while(x!=NULL){
            temp.push_back(x->val);
            x=x->next;
        }
        int n=temp.size();
        int res=INT_MIN;
        for(int i=0;i<(n+1)/2;i++){
            int x=temp[i]+temp[n-i-1];
             cout<<x;
            res=max(res,x);
        }
        return res;
    }
};