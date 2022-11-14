class Solution {
public:
    /* 
    * Approach:
    * floyd's hare and tortoise algorithm
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    bool isHappy(int n) 
    {
        int slow = n, fast = getNext(n);
        while(fast != 1 && slow != fast)
            slow = getNext(slow), fast = getNext(getNext(fast));
        
        return fast == 1;
    }
    
    int getNext(int n)
    {
        int digitsSum{};
        while(n)
        {
            int d = n % 10;
            digitsSum += d*d;
            n/=10;
        }
        return digitsSum;
    }
};