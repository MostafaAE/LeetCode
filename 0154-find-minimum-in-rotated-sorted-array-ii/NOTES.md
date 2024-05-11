### Approach:
- Similar to [153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) but with duplicates.
- When num[mid] == num[end], we can't make sure that the position of minimum in mid's left or right, so just let upper bound reduce one.
- So in worst case (all duplicates) the time complexity will be `O(n)`.
- But in average case it will be a normal binary search `O(logn)`.