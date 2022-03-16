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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL or head->next == NULL or head->next->next == NULL) return head;
        ListNode* odd_h = head;
        ListNode* even_h = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;
        
        while(even!= NULL and even->next!=NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;
            
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_h;
        return odd_h;
    }
};