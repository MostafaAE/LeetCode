### Approach:
1. Insert all banned numbers into a hash set (`bannedNums`) for quick lookup.
2. Initialize `count` to track the count of valid integers and `remainingSum` to the maximum allowed sum (`maxSum`).
3. Iterate over integers from `1` to `n`:
- If the current integer is not in `bannedNums` and can fit within `remainingSum`, include it:
- Deduct the integer's value from `remainingSum`.
- Increment `count`.
- If `remainingSum` becomes less than the current integer, stop the iteration.
4. Return `count` as the number of valid integers that can be included without exceeding `maxSum`.
​
### Complexity:
- **Time Complexity: `O(n + m)`**, where `m` is the size of the `banned` array
- **Space Complexity: `O(m)`**