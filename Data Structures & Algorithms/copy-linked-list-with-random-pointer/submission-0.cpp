class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* temp = head;
        Node* res = new Node(head->val);
        Node* temp2 = res;

        // Change 1: Map original Node* instead of int value
        unordered_map<Node*, Node*> mp;
        mp[temp] = temp2;

        while (temp->next != nullptr) {
            temp2->next = new Node(temp->next->val);
            // Change 2: Map temp->next to temp2->next
            mp[temp->next] = temp2->next;
            temp = temp->next;
            temp2 = temp2->next;
        }

        temp = head;
        temp2 = res;

        while (temp != nullptr) {
            // Change 3: Remove 'continue' so pointers always advance
            if (temp->random != nullptr) {
                temp2->random = mp[temp->random];
            }
            temp = temp->next;
            temp2 = temp2->next;
        }

        return res;
    }
};
