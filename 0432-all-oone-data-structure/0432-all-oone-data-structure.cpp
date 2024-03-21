/* 
* Approach:
* 1. We can solve it by using a hashtable and a doubly linked list of hashtable of strings,
* each entry in the hashtable will map a key to its node in the linkedlist 
* so we can inc() and dec() in O(1) and also getMaxKey() and getMinKey() in O(1).
*
* 
* 2. We can also solve it using a hashtable that map each key to its frequency and another BBST
* that maps each frequency to its key, using this approach we can implement 
* inc() and dec() in O(logn), and getMaxKey() and getMinKey() in O(1)
*
*/

struct Node{
    int count;
    unordered_set<string> hashSet;
    Node *prev{}, *next{};
    Node(string key, int count) : count(count){
        hashSet.insert(key);
    }
};

struct DoublyLinkedList{
    Node *head = new Node("", INT_MIN);
    Node *tail = new Node("", INT_MAX);
    
    DoublyLinkedList()
    {
        link(head, tail);
    }
    
    Node* front()
    {
        return head->next;
    }
    
    Node* back()
    {
        return tail->prev;
    }
    
    void link(Node* node1, Node* node2)
    {
        node1->next = node2;
        node2->prev = node1;
    }
    
    void push_front(string key, int value)
    {
        Node* node = new Node(key, value);
        link(node, head->next);
        link(head, node);
    }
    
    void erase(Node* node)
    {
        link(node->prev, node->next);
    }
};

class AllOne {
private:
    unordered_map<string, Node*> stringToNode;
    DoublyLinkedList dll;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if(!stringToNode.count(key))
        {
            if(dll.front()->count == 1)
                dll.front()->hashSet.insert(key);
            else
                dll.push_front(key, 1);
            stringToNode[key] = dll.front();
        }
        else{
            Node* node = stringToNode[key];
            node->hashSet.erase(key);
            
            if(node->next->count == node->count + 1)
            {
                stringToNode[key] = node->next;
                node->next->hashSet.insert(key);
            }
            else
            {
                Node* newNode = new Node(key, node->count + 1);
                stringToNode[key] = newNode;
                dll.link(newNode, node->next);
                dll.link(node, newNode);
            }
            
            if(node->hashSet.size() == 0)
            {
                dll.erase(node);
                delete node;
            }
        }
    }
    
    void dec(string key) {
        Node* node = stringToNode[key];
        node->hashSet.erase(key);
        
        if(node->count == 1)
            stringToNode.erase(key);
        else if(node->prev->count == node->count - 1)
        {
            stringToNode[key] = node->prev;
            node->prev->hashSet.insert(key);
        }
        else
        {
            Node* newNode = new Node(key, node->count - 1);
            stringToNode[key] = newNode;
            dll.link(node->prev, newNode);
            dll.link(newNode, node);
        }
        
        if(node->hashSet.size() == 0)
        {
            dll.erase(node);
            delete node;
        }
    }
    
    string getMaxKey() {
        if(stringToNode.size() == 0)
            return "";
        
        return *dll.back()->hashSet.begin(); 
    }
    
    string getMinKey() {
        if(stringToNode.size() == 0)
            return "";
        
        return *dll.front()->hashSet.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */