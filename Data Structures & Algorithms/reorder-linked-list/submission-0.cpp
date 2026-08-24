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
    void reorderList(ListNode* head) {
        ListNode *mid = head  ; 
        ListNode *end = head  ; 

        while ( end->next != nullptr && end->next->next != nullptr ){
        mid = mid->next ;
        end = end->next ->next ; 
        }

        stack <ListNode*> s;

        while ( mid->next != nullptr){
            s.push(mid->next);
            mid = mid ->next ; 

        }
        
       ListNode* temp = head;

        while (!s.empty()) {
            ListNode* last = s.top();
            s.pop();

            ListNode* next = temp->next;

            temp->next = last;
            last->next = next;

            temp = next;
        }

        // End the list
        temp->next = nullptr;
        }
    

};
