class Solution {
public:
    /*
     * Approach
     * Utilize a hash set to store all the jewels, for each stone check if it exists in the hash set.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    int numJewelsInStones(string jewels, string stones) 
    {
        int count{};
        unordered_set<char> hashSet(jewels.begin(), jewels.end());
        
        for(char stone : stones)
            if(hashSet.count(stone))
                count++;
        
        return count;
    }
};