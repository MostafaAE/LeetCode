class Solution {
public:
    /* 
    * Approach:
    * Find the upper bound of the target letter (binary search).
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int start{}, end{(int)letters.size()-1}, result{letters[0]};

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(letters[mid] > target)
                result = letters[mid], end = mid - 1;
            else
                start = mid + 1;
        }

        return result;
    }
};