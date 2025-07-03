class Solution {
public:
    char kthCharacter(int k) 
    {
        int count = 0;

        // Skip over complete groups (powers of 2) until k reaches the target position
        while (k > 1)
        {
            int exp = log2(k - 1);
            int size = 1 << exp;
            k -= size;
            ++count;
        }

        return 'a' + count;
    }
};