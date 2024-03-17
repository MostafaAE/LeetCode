// Definition for doubly-linked list node.
struct Node {
    int key, val;
    Node *prev, *next;
    Node() : val(0), prev(nullptr), next(nullptr) {}
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

struct DoublyLinkedList
{
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int size{};
    
    DoublyLinkedList()
    {
        link(head, tail);
    }

    void link(Node* first, Node* second)
    {
        first->next = second;
        second->prev = first;
    }

    Node* front()
    {
        return head->next;
    }

    Node* back()
    {
        return tail->prev;
    }
    
    void push_front(int key, int value)
    {
        Node* node = new Node(key, value);
        link(node, head->next);
        link(head, node);
        size++;
    }
    
    void erase(Node* node)
    {
        link(node->prev, node->next);
        delete node;
        size--;
    }
};
 
class LRUCache {
private:
    unordered_map<int, Node*> hashMap;
    DoublyLinkedList lru;
    int capacity;

public:
    
    /*
     * Approach:
     * Use a hash map where each key maps to a doubly linked list node
     * When we get a key, put it at the front of the linked list
     * When we put a new key, if the hash map size is less than the capacity, then put it at the front of the linked list, else remove the least recently used node (evict last node in the linked list), and put the new node at the front.
     * When we try to put the same key, update the node value, then put it at the front of the linked list
     *
     * Complexity:
     * Time Complexity : O(1) for both 'get' and 'put'
     */
    
    LRUCache(int capacity) : capacity(capacity) {
    }
    
    void updateLRU(int key, int value)
    {
        if(hashMap.count(key))
            lru.erase(hashMap[key]);
        
        lru.push_front(key, value);
        hashMap[key] = lru.front();
    }

    void evict()
    {
        hashMap.erase(lru.back()->key);
        lru.erase(lru.back());
    }
    
    // O(1)
    int get(int key) 
    {
        if(!hashMap.count(key))
            return -1;
        
        int value = hashMap[key]->val;
        updateLRU(key, value);
        return value;
    }
    
    // O(1)
    void put(int key, int value) 
    {
        if(lru.size == capacity && !hashMap.count(key))
            evict();
        updateLRU(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */