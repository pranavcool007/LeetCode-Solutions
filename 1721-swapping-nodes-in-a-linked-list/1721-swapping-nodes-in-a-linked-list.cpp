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
        // O(N) approach and noob approach
    //     int i = 1;
    //     ListNode* p1 = head;
    //     while(i < k){
    //         p1 = p1->next;
    //         ++i;
    //     }
    //     int len = 0;
    //     ListNode* temp = head;
    //     while(temp->next != NULL){
    //         ++len;
    //         temp = temp->next;
    //     }
    //     i = 1;
    //     int j = len-k+1;
    //     ListNode* p2 = head;
    //     while(i <= j){
    //         ++i;
    //         p2 = p2->next;
    //     }
    //     swap(p1->val,p2->val);
    //     return head;
    // }
        
    // 2 pointer and gap approach
        ListNode* left = head;
        ListNode* right = head;
        ListNode* cur = head;
        
        int counter = 1;
        while(cur != NULL)
        {
            if(counter < k){
                left = left->next;
            }
            if(counter > k){
                right = right->next;
            }
            ++counter;
            cur = cur->next;
        }
        // swapping the values
        swap(left->val,right->val);
        return head;
    }
};