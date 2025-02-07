class Solution {
public:
    /**
    * Approach:
    * 1. Use an unordered map `pairProductsFrequency` to count the frequency of each unique product of pairs of numbers in the input array.
    * 2. For each pair of numbers in the array, calculate their product and increment its count in the map.
    * 3. After counting the product frequencies:
    *    - For each unique product, calculate the number of ways to choose two pairs that have the same product. 
    *      This is done using the formula: `C(n, 2) = (frequency * (frequency - 1)) / 2`, where `n` is the frequency of the product.
    *    - Multiply the result by 8 because each pair combination can form 8 tuples.
    * 4. Sum the total number of tuples for all products and return the result.
    *
    * Complexity:
    * - Time Complexity: O(n^2), where `n` is the size of the input array, as we iterate over all pairs of numbers.
    * - Space Complexity: O(k), where `k` is the number of unique products, due to the storage in the unordered map.
    **/
    int tupleSameProduct(vector<int>& nums) 
    {
        int numsLength = nums.size();

        // Initialize an unordered map to store the frequency of each product of pairs
        unordered_map<int, int> pairProductsFrequency;

        int totalNumberOfTuples = 0;

        // Calculate the frequency of each product for all pairs
        for (int i = 0; i < numsLength; i++) 
        {
            for (int j = i + 1; j < numsLength; j++) 
            {
                int product = nums[i] * nums[j];
                ++pairProductsFrequency[product];
            }
        }

        // Calculate the total number of tuples from the product frequencies
        for (auto [productValue, productFrequency] : pairProductsFrequency) 
        {
            // Calculate the number of ways to choose two pairs with the same product
            int pairsOfEqualProduct = (productFrequency - 1) * productFrequency / 2;

            // Add the number of tuples for this product to the total (each pair can form 8 tuples)
            totalNumberOfTuples += 8 * pairsOfEqualProduct;
        }

        return totalNumberOfTuples;
    }
};