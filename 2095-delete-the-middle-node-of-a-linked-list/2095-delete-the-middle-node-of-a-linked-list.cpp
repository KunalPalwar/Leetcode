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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next == nullptr) return nullptr;
        ListNode* first = head;
        ListNode* prev = head;
        ListNode* second = head;
        while(second && second->next){
            prev = first;
            first = first->next;
            second = second->next->next;
        }
      
        prev->next = prev->next->next;
        
        return head;
    }
};