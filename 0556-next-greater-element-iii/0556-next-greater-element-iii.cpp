class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n) where n is the number of digits in the input
    */
    int nextGreaterElement(int number) 
    {
        string num{to_string(number)};
        int i{(int)num.size()-2}, j{(int)num.size()-1};
        
        while(i >= 0 && num[i] >= num[i+1])
            i--;
        
        if(i == -1)
            return -1;

        while(num[j] <= num[i])
            j--;

        swap(num[j], num[i]);
        reverse(num.begin()+i+1, num.end());
    
        long long res = stoll(num);
        if(res > INT_MAX)
            return -1;
        return (int)res;
    }
    
};