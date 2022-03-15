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
public:
    ListNode* sortList(ListNode* head) {
        // merge sort in link list 
        // do merge 2 sorted list ques first
        if(head == NULL or head->next==NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nhead = slow->next;
        slow->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(nhead);
        ListNode* ans = mergeTwoLists(l1,l2);
        return ans;
    }
    
};