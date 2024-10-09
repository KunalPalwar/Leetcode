/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* checker(Node* head){
        if(head == nullptr) return head;
        if(head->next == nullptr && head->child == nullptr) return head;
        
        while(head->next || head->child){
            Node* current = head;
            Node* next = head->next;
            Node* child = head->child;
            
            Node* lastNode = checker(child);
            if(lastNode == nullptr){
                head = next;
                continue;
            }
            
            current->next = child;
            head->child = nullptr;
            if(child != nullptr){
                child->prev = current;
            }
            if(lastNode != nullptr){
                lastNode->next = next;
            }
            if(next !=nullptr){
                next->prev = lastNode;
            }
            
            head = lastNode;
        }
        return head;
        
    }
    Node* flatten(Node* head) {
        Node* current = head;
        checker(head);
        return current;
        
    }
};