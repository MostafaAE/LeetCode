class Solution {
public:
    /* 
    * Approach:
    * find upper bound of the target letter
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int start{0}, end{(int)letters.size()-1};
    
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            
            if(target < letters[mid])
                end = mid - 1;
            
            else
                start = mid + 1;
        }
        
        if(start < (int)letters.size())
            return letters[start];
        
        return letters[0];
    }
};