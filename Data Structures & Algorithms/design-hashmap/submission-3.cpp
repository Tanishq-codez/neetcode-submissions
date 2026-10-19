class Node {
    public : 
    Node* next;
    int val, key;
    Node(int val,int  key) {
        this->val = val;
        this->key = key;
        next = nullptr;
    }
};
class MyHashMap {
   public:
    vector<Node*> map;
    MyHashMap() { map.resize(1000, nullptr); }

    void put(int key, int value) {
        int hash = key % 1000;

        if (map[hash] != nullptr) {
            Node* head = map[hash];
            while (head != nullptr)
               { if (head->key == key) {
                head->val = value ; 
                return;
               }
            head = head->next;}
        }
        Node *temp = new Node(value, key);
        temp->next = map[hash];
        map[hash] = temp;
    }

    int get(int key) {
        int hash = key % 1000;
        if (map[hash] != nullptr)

        {
            Node* head = map[hash];
            while (head != nullptr)
               { if (head->key == key) return head->val;
            head = head->next;}
        }

        return -1;
    }

    void remove(int key) {
        int hash = key % 1000;
        if (map[hash] != nullptr)

        {
            Node* head = map[hash];
            Node* prev = nullptr ;
            while (head != nullptr) {
                if (head->key == key) {
                
                if ( prev == nullptr){
                    map[hash] = head ->next ; 
                }

                else {
                prev->next = head->next ;
                }
                delete head ; 
                return ; 
                };
                prev = head ;

                head = head ->next ; 
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */