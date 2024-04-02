### Approach:
- Utilize a vector of vector of pairs, at each index store the value with it's snap_id.
- By using binary search we can get the value at a certain snap id in `O(logm)` where m is the number of snaps stored at this index.