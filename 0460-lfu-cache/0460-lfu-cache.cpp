// Definition for doubly-linked list node.
struct Node {
    int key, val, freq;
    Node *prev, *next;
    Node() : val(0), prev(nullptr), next(nullptr) {}
    Node(int key, int val, int freq) : key(key), val(val), freq(freq), prev(nullptr), next(nullptr) {}
};

struct DoublyLinkedList
{
    Node *head = new Node();
    Node *tail = new Node();
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
    
    void unlink(Node* node)
    {
        link(node->prev, node->next);
        size--;
    }

    Node* front()
    {
        return head->next;
    }

    Node* back()
    {
        return tail->prev;
    }
    
    void push_front(int key, int value, int freq)
    {
        Node* node = new Node(key, value, freq);
        link(node, head->next);
        link(head, node);
        size++;
    }
    
    void erase(Node* node)
    {
        unlink(node);
        delete node;
    }
};

class LFUCache {
private:
    unordered_map<int, Node*> keyToNode;
    unordered_map<int, DoublyLinkedList*> freqToLinkedList;
    int capacity, size, leastFreq{1};
    
public:
    LFUCache(int capacity) : capacity(capacity), size(0) {}
    
    // evict from cache
    void evict()
    {
        DoublyLinkedList* dll = freqToLinkedList[leastFreq];
        keyToNode.erase(dll->back()->key);
        dll->erase(dll->back());
        if(dll->size == 0)
        {
            delete dll;
            freqToLinkedList.erase(leastFreq);
        }
        size--;
    }
    
    // update cache
    void updateLFU(int key, int value)
    {
        int freq{};
        if(keyToNode.count(key))
        {
            freq = keyToNode[key]->freq;
            freqToLinkedList[freq]->erase(keyToNode[key]);
            if(freqToLinkedList[freq]->size == 0)
            {
                delete freqToLinkedList[freq];
                freqToLinkedList.erase(freq);
                if(freq == leastFreq)
                    leastFreq = freq + 1;
            }
                
        }
        
        freq++;
        if(!freqToLinkedList.count(freq))
            freqToLinkedList[freq] = new DoublyLinkedList();
        
        freqToLinkedList[freq]->push_front(key, value, freq);
        keyToNode[key] = freqToLinkedList[freq]->front();
        leastFreq = min(leastFreq, freq);
    }
    
 
    int get(int key) 
    {
        if(!keyToNode.count(key))
            return -1;
        
        int value = keyToNode[key]->val;
        updateLFU(key, value);
        return value;
    }
    
    void put(int key, int value) 
    {
        if(!keyToNode.count(key) && size == capacity)
            evict();
        
        if(!keyToNode.count(key))
            size++;
        
        updateLFU(key, value);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */