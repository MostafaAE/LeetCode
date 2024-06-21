class Solution {
public:
    /*
    * Approach:
    * - Calculate the number of customers that are satisfied when the owner is not grumpy.
    * - Use a sliding window to find the maximum number of additional satisfied customers that can be achieved by using the secret technique for 'minutes' duration.
    * - Slide the window across the grumpy array and calculate the sum of customers that can be satisfied in the window where the owner uses the secret technique.
    * - The final result is the sum of normally satisfied customers and the maximum additional satisfied customers achieved by the secret technique.
    * 
    * Complexity:
    * - Time Complexity: O(n)
    * - Space Complexity: O(1)
    */
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int n = customers.size(), normallySatisfied = 0;

        // Calculate the number of customers satisfied without using the secret technique
        for(int i = 0; i < n; ++i)
            normallySatisfied += customers[i] * !grumpy[i];
        
        int maxSatisfiedBySecret = 0, windowSum = 0;
        // Sliding window to find the maximum additional satisfied customers
        for(int right = 0; right < n; ++right)
        {
            if(right >= minutes)
                windowSum -= customers[right - minutes] * grumpy[right - minutes];
            
            windowSum += customers[right] * grumpy[right];
            
            maxSatisfiedBySecret = max(maxSatisfiedBySecret, windowSum);
        }
        
        return normallySatisfied + maxSatisfiedBySecret;
    }
};
