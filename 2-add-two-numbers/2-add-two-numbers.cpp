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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(1);
        ListNode* prev = dummy;
        int carry = 0;
        while(l1!=NULL or l2!=NULL or carry!=0){ // loop will continue till
                                        // l2 and l2 is reached null and carry = 0
            int sum = 0;
            if(l1!=NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            
            ListNode* temp = new ListNode(sum%10);
            prev->next = temp;
            prev = prev->next;
            
        }
        return dummy->next;
    }
};