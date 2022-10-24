class Solution {
public:
    /* 
    * Approach:
    * binary search the square root value
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int mySqrt(int x) 
    {
        const double EPS{1e-9};
        
        double start = 0, end = x;
        
        while(end-start > EPS)
        {
            double mid = start + (end-start)/2;
            
            if(possibleSqrt(x, mid, EPS))
                start = mid;
            else
                end = mid;
        }
        
        return start+EPS;
    }
    
    bool possibleSqrt(int x, double s, double EPS)
    {
        return s*s - x < EPS;
    }
};