### Approach:
1. We can solve it by using a hashtable and a doubly linked list of hashtable of strings, each entry in the hashtable will map a key to its node in the linkedlist so we can inc() and dec() in O(1) and also getMaxKey() and getMinKey() in O(1) *(harder to code)*.
​
2. We can also solve it using a hashtable that map each key to its frequency and another BBST that maps each frequency to its key, using this approach we can implement inc() and dec() in O(logn), and getMaxKey() and getMinKey() in O(1) *(easier to code relative to approach 1)*.