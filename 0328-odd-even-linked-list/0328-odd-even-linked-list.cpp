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
        
        ListNode* firstNode = new ListNode(-1);
        ListNode* secondNode = new ListNode(-1);
        ListNode* first = firstNode;
        ListNode* second  = secondNode;
        ListNode* temp = first;
        ListNode* tempSecond = second;
        int count = 1;
        while(head!=nullptr){
            if(count%2 == 1){
                count = 0;
                first->next = head;
                first = first->next;
                  head = head->next;
                first->next = nullptr;
                
            }else{
                count = 1;
                second->next = head;
                second = second->next;
                                  head = head->next;

                second->next = nullptr;
            }
          
        }
        
        first->next = tempSecond->next;
        
        return temp->next;
        
    }
};