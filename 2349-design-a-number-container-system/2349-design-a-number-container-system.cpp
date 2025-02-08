class NumberContainers 
{
private:
    /**
     * A hash map to store the mapping of indices to numbers.
     * A hash map to store the mapping of numbers to a sorted set of indices where the number occurs.
     **/
    unordered_map<int, int> idxToNumber;
    unordered_map<int, set<int>> numberToIndecies;

public:
    /**
     * Approach:
     * 1. Use two unordered maps:
     *    - `idxToNumber`: Maps an index to its associated number.
     *    - `numberToIndecies`: Maps a number to a sorted set of indices where the number is stored.
     * 2. For the `change` operation:
     *    - If the index already has a number, remove it from the `numberToIndecies` of the old number.
     *    - Update the `idxToNumber` and insert the index into the set for the new number in `numberToIndecies`.
     *    - Ensure to remove empty sets in `numberToIndecies` for old numbers.
     * 3. For the `find` operation:
     *    - If the number is present in `numberToIndecies`, return the smallest index (using the `set` structure).
     *    - If the number is not present, return -1.
     *
     * Complexity:
     * - `change`:
     *   - Time Complexity: O(log k), where `k` is the number of indices associated with the old or new number (due to the `set` operations).
     *   - Space Complexity: O(n), where `n` is the number of unique indices stored.
     * - `find`:
     *   - Time Complexity: O(1) for map access and O(1) for fetching the smallest index.
     *   - Space Complexity: O(n).
     **/
    NumberContainers() {}

    void change(int index, int number) 
    {
        // If the index already has a number, remove it from the set of the old number
        if(idxToNumber.count(index))
        {
            int oldNumber = idxToNumber[index];
            
            if(oldNumber == number)
                return;

            // Remove the index from the old number's set
            numberToIndecies[oldNumber].erase(index);
            if(numberToIndecies[oldNumber].empty())
                numberToIndecies.erase(oldNumber);
        }
        
        // Update the index-to-number mapping
        idxToNumber[index] = number;
        // Insert the index into the new number's set
        numberToIndecies[number].insert(index);
    }
    
    int find(int number) 
    {
        // Return the smallest index associated with the number if it exists
        if(!numberToIndecies.count(number))
            return -1;
        
        return *numberToIndecies[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
