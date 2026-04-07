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
    bool hasCycle(ListNode* head) {
        if (head== nullptr  || head->next == nullptr  ) return false ;
        ListNode* t1 = head ;
       ListNode* t2 = head ; 

        while ( t2 ->  next  != nullptr && t2 -> next -> next  != nullptr ){
            
            t1 = t1 -> next ;
            t2= t2 -> next -> next ; 
            if (t1 == t2 ){
                return true ; 
            }
        }
        return false ; 
    }
};
