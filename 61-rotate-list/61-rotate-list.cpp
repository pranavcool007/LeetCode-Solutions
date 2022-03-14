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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        int len = 1;
        ListNode* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
            len++;
        }
        if(k>=len){
            k = k%len;
        }
        temp->next = head;
        int i = len - k;
        temp = head;
        while(i>1){
            temp = temp->next;
            --i;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
        
    }
};