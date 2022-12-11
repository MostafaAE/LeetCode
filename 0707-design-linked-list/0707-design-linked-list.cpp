class Node
{
public:
    int val;
    Node* next;
    Node(){}
    Node(int val) : val(val){next = nullptr;}
};
class MyLinkedList {
private:
    Node* head, *tail;
    int size;
    
public:
    MyLinkedList() 
    {
        head = tail = nullptr;
        size = 0;
    }
    
    int get(int index) 
    {
        if(index >= size)
            return -1;
        
        Node* cur = head;
        for(int i = 0 ; i < index ; i++)
            cur = cur->next;
        
        return cur->val;
    }
    
    void addAtHead(int val) 
    {
        Node* newNode = new Node(val);
        size++;
        if(!head)
        {
            head = tail = newNode;
            return;
        }
        
        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) 
    {
        Node* newNode = new Node(val);
        size++;
        if(!head)
        {
            head = tail = newNode;
            return;
        }
        
        tail->next = newNode;
        tail = newNode;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index == size)
        {
            addAtTail(val);
            return;
        }
        else if(index == 0)
        {
            addAtHead(val);
            return;
        }
        else if(index > size)
            return;
        
        Node* prev = nullptr, *cur = head;
        for(int i = 0 ; i < index ; i++)
            prev = cur, cur = cur->next;
        
        Node* newNode = new Node(val);
        prev->next = newNode;
        newNode->next = cur;
        size++;
    }
    
    void deleteAtIndex(int index) 
    {
        if(index >= size)
            return;
        
        size--;
        
        // 1 node only
        if(head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        
        Node* prev = nullptr, *cur = head;
        for(int i = 0 ; i < index ; i++)
            prev = cur, cur = cur->next;
        
        if(cur == head)
            head = head->next;
        else if (cur == tail)
            prev->next = nullptr, tail = prev;
        else
            prev->next = cur->next;
        
        delete cur;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */