#include <vector>
using namespace std;

class Node {
public:  // Changed: members and constructor must be accessible
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

class MyHashSet {
    vector<Node*> map;  // Changed: class member, not local variable

    Node* removeNode(Node* curr, int key) {
        if (curr == nullptr) return nullptr;

        if (key < curr->value)
            curr->left = removeNode(curr->left, key);
        else if (key > curr->value)
            curr->right = removeNode(curr->right, key);
        else {
            if (curr->left == nullptr) {
                Node* temp = curr->right;
                delete curr;
                return temp;
            }
            if (curr->right == nullptr) {
                Node* temp = curr->left;
                delete curr;
                return temp;
            }

            Node* temp = curr->right;
            while (temp->left != nullptr)
                temp = temp->left;

            curr->value = temp->value;
            curr->right = removeNode(curr->right, temp->value);
        }

        return curr;
    }

public:
    MyHashSet() : map(1000, nullptr) {}

    void add(int key) {
        int hash = key % 1000;

        if (map[hash] == nullptr) {
            map[hash] = new Node(key);
            return;
        }

        Node* curr = map[hash];

        while (true) {
            if (curr->value == key) return;

            if (key < curr->value) {
                if (curr->left == nullptr) {
                    curr->left = new Node(key);
                    return;
                }
                curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    curr->right = new Node(key);
                    return;
                }
                curr = curr->right;
            }
        }
    }

    void remove(int key) {
        int hash = key % 1000;
        map[hash] = removeNode(map[hash], key);
    }

    bool contains(int key) {
        int hash = key % 1000;
        Node* curr = map[hash];

        while (curr != nullptr) {
            if (curr->value == key) return true;

            if (key < curr->value)
                curr = curr->left;
            else
                curr = curr->right;
        }

        return false;
    }
};