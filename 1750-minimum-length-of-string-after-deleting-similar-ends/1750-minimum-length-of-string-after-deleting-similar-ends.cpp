class Solution {
public:
    /*
     * Approach:
     * Two pointers approach
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1)
     */
    int minimumLength(string s) 
    {
        int n{(int)s.size()}, left{}, right{n - 1};
        
        while(left < right)
        {
            if(s[left] != s[right])
                return right - left + 1;
            else
            {
                while(left < right - 1 && s[left] == s[left + 1])
                    left++;
                while(right > left + 1 && s[right] == s[right - 1])
                    right--;
                
                left++;
                right--;
            }
        }
        
        return left == right;
    }
};