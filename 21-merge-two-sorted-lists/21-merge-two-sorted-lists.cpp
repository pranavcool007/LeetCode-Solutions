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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        
        if(l1 == NULL or l2 == NULL){
            return l1!=NULL?l1:l2;      // if any one list is empty
        }
        
        while(l1 != NULL and l2 != NULL){
            if(l1->val < l2->val){
                prev->next = l1;
                l1 = l1->next;
            }else{
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        
        if(l1 != NULL){       // when one list is bigger than other
                              // just join the remaining part of the bigger list
            prev->next = l1;
        }else if(l2 != NULL){
            prev->next = l2;
        }
        return dummy->next;
        
    }
};