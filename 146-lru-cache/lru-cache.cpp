#include <unordered_map>

class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    std::unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* resNode = mp[key];
            int res = resNode->value;
            deleteNode(resNode);
            addNode(resNode);
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
       
        if (mp.find(key) != mp.end()) {
            Node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
            delete existingNode;
        }

       
        if (mp.size() == cap) {
            Node* lruNode = tail->prev;
            mp.erase(lruNode->key);
            deleteNode(lruNode);
            delete lruNode;
        }

        
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */