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
    
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(head){
            ListNode* next =head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;
        
        while(second && second->next){
            temp = first;
            first = first->next;
            second = second->next->next;
        }
        temp->next = reverse(first);
        first = head;
        temp = temp->next;
        int count = 0;
        while(temp){
            count = max(count,first->val+temp->val);
            first = first->next;
            temp = temp->next;
        }
        return count;
    }
};