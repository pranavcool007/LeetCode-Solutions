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
class comp{
    public:
    bool operator ()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;     // for empty list []
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        priority_queue<ListNode*,vector<ListNode*>,comp> minh;
        for(auto list : lists){
            if(list){                          // we do not have to put NULL list in heap
                                               // [[]]
                minh.push(list);
            }
        }
        while(minh.size() > 0){
            ListNode* cur = minh.top();
            minh.pop();
            
            prev->next = cur;
            prev = prev->next;
            cur = cur->next;
            
            if(cur != NULL){
                minh.push(cur);
            }
            
        }
        return dummy->next;
    }
};