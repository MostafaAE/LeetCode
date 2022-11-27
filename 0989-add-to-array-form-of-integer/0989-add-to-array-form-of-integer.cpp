class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(max(n, logk))
    * Space Complexity : O(1)
    */
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        int i{}, n{(int)num.size()};
        
        // O(n)
        reverse(num.begin(), num.end());
        
        while(k)
        {
            if(i < n)
                k += num[i], num[i++] = k % 10;
            
            else
                num.push_back(k % 10);
            
            k/=10;
        }
        
        reverse(num.begin(), num.end());
        return num;
    }
};