### Approach:
- Calculate the wage-to-quality ratio for each worker and store it in a set along with the worker's index (sort workers in ascending order by wage-to-quality ratio).
- Utilize a max heap to store the quality of the selected workers.
- For each ratio, if the size of the max heap is equal to k, pop the worker with the highest quality from the heap and update the total quality sum accordingly.
- Add the quality of the current worker to the heap and update the total quality sum.
- At each step, calculate the total cost based on the current ratio and the total quality sum.
- Update the result with the minimum cost seen so far, and finally, return the minimum cost.
​
### Complexity:
- **Time Complexity: `O(n logn + n logk)`**, where n is the number of workers.
- **Space Complexity: `O(n + k)`**, for storing the wage-to-quality ratios and the max heap.