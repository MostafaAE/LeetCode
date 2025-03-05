class Solution {
public:
    long long coloredCells(int n) 
    {
        return 1 + 2 * ((long long)n * (n - 1));
    }
};