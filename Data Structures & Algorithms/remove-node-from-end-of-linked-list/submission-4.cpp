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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if ( head == nullptr || head->next == nullptr) return nullptr ;
        ListNode * temp1 = head ;
        ListNode * temp2 = head ;

        while (temp2!= nullptr && n !=0){
            temp2=temp2->next ;
            n-- ; 
        }
        if (temp2 == nullptr)
        return head->next;
        ListNode *prev = head;
        while ( temp2!= nullptr){
            prev = temp1 ; 
            temp1 = temp1->next ; 
            temp2 = temp2->next ; 
        }
        prev ->next = temp1->next ;



        return head  ; 



    }
};
