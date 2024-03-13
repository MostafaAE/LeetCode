### Approach:
Use a hash map where each key maps to a doubly linked list node\
When we get a key, unlink its node and put it in the end of the linked list\
When we put a new key, if the hash map size is less than the capacity, then put it at the end of the linked list, else remove the least recently used node (first node in the linked list), and put the new node at the end.\
When we try to put the same key, update the node value, then put it at the end of the linked list.
​
### Complexity:
**Time Complexity : `O(1)` for both `get` and `put`**