class Solution {
public:
    /*
    * Approach:
    * - Simulate the binary number reduction process step by step.
    * - Use a carry to handle the addition of 1 when the current bit is '1' or when there's a carry from a previous step.
    * - Iterate through the string from the last bit to the first bit (excluding the most significant bit).
    * - Depending on the value of the current bit and the carry, decide the number of steps required and update the carry.
    *
    * Complexity:
    * - Time Complexity: O(n)
    * - Space Complexity: O(1)
    */
    int numSteps(string s) 
    {
        int n = s.size(), steps{}, carry{};
        
        for (int i = n - 1; i > 0; i--) 
        {
            // We have 4 cases:
            // 1. s[i] == '1' and no carry, then we add 1 and divide by 2 (2 steps)
            // 2. s[i] == '0' and there is carry, then we add 1 and divide by 2 (2 steps)
            // 3. s[i] == '1' and there is carry, then we divide by 2 (1 step)
            // 4. s[i] == '0' and no carry, then we divide by 2 (1 steps)
            if (((s[i] - '0') + carry) % 2) 
            {
                steps += 2;
                carry = 1;
            } 
            else
                ++steps;
        }

        // Add the carry to the steps if there is any carry left
        return steps + carry;
    }
};