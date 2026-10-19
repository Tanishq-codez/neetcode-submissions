#include <vector>
using namespace std;

class Node { 
public: 
    Node* next; 
    int val, key; 
    Node(int val, int key) { 
        this->val = val; 
        this->key = key; 
        next = nullptr; 
    } 
}; 

class MyHashMap { 
public: 
    vector<Node*> map; 
    
    MyHashMap() { 
        map.resize(1000, nullptr); 
    } 
    
    void put(int key, int value) { 
        int hash = key % 1000; 
        Node* head = map[hash]; 
        
        // 1. Check if key already exists, if so, update value
        while (head != nullptr) {
            if (head->key == key) {
                head->val = value;
                return;
            }
            head = head->next;
        }
        
        // 2. If key doesn't exist, insert new node at the front of the chain
        Node* temp = new Node(value, key); 
        temp->next = map[hash]; 
        map[hash] = temp; 
    } 
    
    int get(int key) { 
        int hash = key % 1000; 
        Node* head = map[hash]; 
        
        // Search the chain
        while (head != nullptr) { 
            if (head->key == key) return head->val; 
            head = head->next; 
        } 
        return -1; 
    } 
    
    void remove(int key) { 
        int hash = key % 1000; 
        Node* head = map[hash]; 
        Node* prev = nullptr; 
        
        while (head != nullptr) { 
            if (head->key == key) { 
                if (prev == nullptr) {
                    // Node to remove is the head of the chain
                    map[hash] = head->next;
                } else {
                    // Node to remove is in the middle or end
                    prev->next = head->next;
                }
                delete head; // Free memory to avoid memory leaks
                return; 
            } 
            prev = head; 
            head = head->next; 
        } 
    } 
};
