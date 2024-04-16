### Approach:
- Tweak the original linked list. interweave the nodes of the old and copied list. For example: Old List: A --> B --> C --> D. InterWeaved List: A --> A' --> B --> B' --> C --> C' --> D --> D'. Then connect the random pointers of the new list to the new nodes and finally split the two lists.
- Another approach: Utilize a hashmap and iterate over the linkedlist mapping each old node to the new copy node, then iterate again to copy the pointers. O(n) space.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`** *=> ignoring the new list space*