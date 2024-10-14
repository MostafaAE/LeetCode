### Approach:
- We use a max-heap (priority queue) to always select the largest element at each step.
- After selecting the largest element, we increment the score and reduce the element by dividing it by 3, pushing the reduced value back into the heap.
​
### Complexity:
- **Time Complexity: `O(klogn + nlogn)`**, where `n` is the number of elements in the array `nums`, and `k` is the number of selections.
- **Space Complexity: `O(n)`**, for the heap to store `n` elements.