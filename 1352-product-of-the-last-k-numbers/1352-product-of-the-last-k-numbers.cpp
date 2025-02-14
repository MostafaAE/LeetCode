class ProductOfNumbers {
private:
    vector<int> prefix = {1};
    int size = 0;

public:
    /**
     * Approach:
     * 1. Use a prefix product array to efficiently calculate the product of the last `k` numbers.
     * 2. In the `add(int num)` method:
     *    - If `num` is 0, reset the prefix array to `{1}` and size to 0, since all products involving this number will be 0.
     *    - Otherwise, multiply the current number with the last value in `prefix` and append the result to `prefix`.
     * 3. In the `getProduct(int k)` method:
     *    - If `k` is greater than the number of non-zero elements, return 0 (as it involves a product with zero).
     *    - Otherwise, return the product using the formula: 
     *          `prefix[size] / prefix[size - k]`
     *      This gives the product of the last `k` numbers by dividing the total product up to the current point by the product before the last `k` numbers.
     *
     * Complexity:
     * - Time Complexity:
     *    - `add(int num)`: O(1) per operation
     *    - `getProduct(int k)`: O(1) per operation
     * - Space Complexity: O(n), where `n` is the number of elements added, for storing the prefix product array.
     **/
    ProductOfNumbers() { }
    
    void add(int num) 
    {
        // If num is zero, reset prefix array and size
        if(num == 0)
        {
            prefix = {1}; // Reset prefix to handle zero
            size = 0;
        }
        else
        {
            // Add the product of the current number with the last prefix product
            prefix.push_back(num * prefix.back());
            ++size;
        }
    }
    
    int getProduct(int k) 
    {
        // If k is greater than the number of non-zero elements, return 0
        if(k > size)
            return 0;

        // Calculate product of the last k numbers
        return prefix[size] / prefix[size - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */