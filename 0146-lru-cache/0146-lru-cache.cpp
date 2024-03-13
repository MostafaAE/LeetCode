// Definition for doubly-linked list.
struct DoublyListNode {
    int key, val;
    DoublyListNode *prev, *next;
    DoublyListNode() : val(0), prev(nullptr), next(nullptr) {}
    DoublyListNode(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
    DoublyListNode(int key, int val, DoublyListNode *prev, DoublyListNode *next) :key(key), val(val), prev(prev), next(next) {}
    
    
};
 
class LRUCache {
private:
    DoublyListNode *head = new DoublyListNode(-1, -1), *tail = new DoublyListNode(-1, -1);
    unordered_map<int, DoublyListNode*> hashMap;
    int capacity;
    
    void addLast(DoublyListNode *node)
    {
        // insert the new node at the end of the linked list
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }
    
    void unlink(DoublyListNode *node)
    {
        DoublyListNode* prev = node->prev;
        DoublyListNode* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
public:
    
    /*
     * Approach:
     * Use a hash map where each key maps to a doubly linked list node
     * When we get a key, unlink it and put it in the end of the linked list
     * When we put a new key, if the hash map size is less than the capacity, then put it at the end of the linked list, else remove the least recently used node (first node in the linked list), and put the new node at the end.
     * When we try to put the same key, update the node value, then put it at the end of the linked list
     * Complexity:
     * Time Complexity : O(1) for both 'get' and 'put'
     */
    
    LRUCache(int capacity) : capacity(capacity) {
        head->next = tail;
        tail->prev = head;
    }
    
    // O(1)
    int get(int key) {
        if(hashMap.count(key))
        {
            DoublyListNode* cur = hashMap[key];
            
            // unlink this node
            unlink(cur);
            
            // insert the node at the end of the linked list
            addLast(cur);
            
            return cur->val;
        }
        else
            return -1;
    }
    
    // O(1)
    void put(int key, int value) 
    {
        // key already exists
        if(hashMap.count(key))
        {
            // update its value
            DoublyListNode *node = hashMap[key];
            node->val = value;
            
            // unlink this node
            unlink(node);
            // insert the node at the end of the linked list
            addLast(node);
            
            return;
        }
        
        DoublyListNode *node = new DoublyListNode(key, value);
        
        if(hashMap.size() >= capacity)
        {
            // unlink least recently used node
            DoublyListNode* temp = head->next;
            unlink(temp);
            
            hashMap.erase(temp->key);
            delete temp;
        }
        
        // insert the new node at the end of the linked list
        addLast(node);
        
        hashMap.insert({key, node});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */