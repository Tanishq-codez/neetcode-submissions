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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* head = new ListNode();
        ListNode* temp = head;
        while (l1 != nullptr && l2 != nullptr) {
            int res = l1->val + l2->val + c;

            c = res / 10;
            int value = res % 10;

            temp->next = new ListNode(value);

            temp = temp->next ;
            l1 = l1 ->next ;
            l2 = l2 ->next ;
        }

        while ( l1 != nullptr){
            int res = l1->val  + c;

            c = res / 10;
            int value = res % 10;

            temp->next = new ListNode(value);

            temp = temp->next ;
            l1 = l1 ->next ;
           
        }

        while ( l2 != nullptr){
            int res =  l2->val + c;

            c = res / 10;
            int value = res % 10;

            temp->next = new ListNode(value);

            temp = temp->next ;
            l2 = l2 ->next ;
        }

        if (c!= 0){
            temp->next = new ListNode(c);
        }

        return head->next;
    }
};
