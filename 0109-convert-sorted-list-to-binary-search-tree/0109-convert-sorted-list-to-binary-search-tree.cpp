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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
static TreeNode* sortedListToBST(const ListNode* head) {
        return sortedListToBST(head, 0, listSize(head));
    }

    static int listSize(const ListNode* head) {
        int length = 0;
        while (head) {
            head = head->next;
            ++length;
        }
        return length;
    }

    static TreeNode* sortedListToBST(const ListNode*& node, int b, int e) {
        if (b == e) return nullptr;
        
        const int mid = b + (e - b) / 2;

        // Construct the left sub-tree.
        TreeNode* left = sortedListToBST(node, b, mid);
        // Consume the next node in the list.
        const int val = node->val;
        node = node->next;
        // Construct the right sub-tree.		
        TreeNode* right = sortedListToBST(node, mid + 1, e);

        return new TreeNode(val, left, right);
    }
};