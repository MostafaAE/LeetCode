class Solution 
{
public:
    /*
    * Approach:
    * - Alice wins if the sum of (x + y) is odd.
    * - This happens when:
    *     1. x is even and y is odd, OR
    *     2. x is odd and y is even.
    *
    * Steps:
    * 1. Count how many even and odd numbers are in [1..n] (for x) 
    *    and [1..m] (for y).
    *    - Even count = n / 2
    *    - Odd count = n - even
    *    (Same for m)
    * 2. Compute valid pairs:
    *    - evenX * oddY  (case 1)
    *    - oddX * evenY  (case 2)
    * 3. Return the sum of these pairs as the result.
    *
    * Time Complexity: O(1)
    * Space Complexity: O(1)
    */
    long long flowerGame(int n, int m) 
    {
        // Count even and odd numbers in [1..n]
        int evenX = n / 2;
        int oddX = n - evenX;

        // Count even and odd numbers in [1..m]
        int evenY = m / 2;
        int oddY = m - evenY;

        // Alice wins if (x even & y odd) OR (x odd & y even)
        return (long long)evenX * oddY + (long long)oddX * evenY;;
    }
};
