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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        // breaking the list into 2 parts first and second using f and s pointers
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* first = head;
        ListNode* sec = slow->next;
        slow->next = NULL;
        
        sec = reverseList(sec); // reverse the second part
        
        while(sec!=NULL){       // sec list will be always smaller
            ListNode* t1 = first->next;
            ListNode* t2 = sec->next;
            first->next = sec;
            sec->next = t1;
            first = t1;
            sec = t2;
            
        }
    }
};