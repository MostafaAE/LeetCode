class Solution {
public:
    int findClosest(int x, int y, int z) 
    {
        int diffX = abs(x-z), diffY = abs(y-z);

        if(diffX == diffY)
            return 0;
        
        return diffX < diffY ? 1 : 2;
    }
};