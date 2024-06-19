### Approach:
- Pair each job's difficulty with its profit and sort the jobs by difficulty.
- Sort the workers by their ability.
- Iterate over each worker, and for each worker, find the maximum profit they can achieve based on their ability.
- Use a two-pointer technique to keep track of the most profitable job that each worker can do.
​
### Complexity:
- **Time Complexity: `O(n logn + m logm)`**, Sorting the jobs takes O(n log n), Sorting the workers takes O(m log m), The iteration over the workers and jobs together takes O(m + n).
- **Space Complexity: `O(n)`**, The extra space used is for storing the job pairs.