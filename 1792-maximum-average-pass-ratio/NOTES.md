### Approach:
1. Use a max-heap to prioritize the class that benefits the most from adding an extra student.
The benefit is defined as the increase in pass ratio:
`(pass + 1) / (total + 1) - pass / total`.
2. Push all classes into the heap, storing the potential increase in ratio and the class index.
3. While extra students are available:
- Pop the top class from the heap.
- Update its `pass` and `total` values by adding one student.
- Recalculate its benefit and push it back into the heap.
4. Calculate the final average pass ratio by summing the pass ratios of all classes.
​
### Complexity:
- **Time Complexity: `O((n+k) * logn)`**
- **Space Complexity: `O(n)`**