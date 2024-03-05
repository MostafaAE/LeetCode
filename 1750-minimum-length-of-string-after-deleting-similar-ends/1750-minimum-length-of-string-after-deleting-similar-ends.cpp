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
        
        while(left < right && s[left] == s[right])
        {
            char c = s[left];
            while(left <= right && s[left] == c)
                left++;
            while(right >= left && s[right] == c)
                right--;
        }
        
        return right - left + 1;
    }
};