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
/* 
   find the middle using fast and slow pointers, make new node of the found middle element
   now cut the list into left part and right part by making prev = NULL. Call the same fun
   for the left subtree(left sublist) and for the right subtree(right sublist).
*/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // base cases when no nodes are left or only one node in the left or right sublist
        if(head == NULL) return NULL;      
        if(head->next == NULL) return new TreeNode(head->val);
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast != NULL and fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};