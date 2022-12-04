class Solution {
private:
const static int MAX = 100 + 1;
int memory[MAX];
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (pick next mask one approach)
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N) where N is the max index
     */
    int maxHeight(vector<vector<int>>& cuboids) 
    {
        // sort each cuboid dimensions to make the height is the biggest
        for(auto& v : cuboids)
            sort(v.begin(), v.end());
        
        // sort cuboids from smallest to largest
        sort(cuboids.begin(), cuboids.end());
        
        memset(memory, -1, sizeof(memory));
        
        cuboids.insert(cuboids.begin(), {0, 0, 0});
        
        // get the maximum height of the longest increasing sequence of cuboids
        return LISHeight(cuboids, 0);
    }
    
    int LISHeight(vector<vector<int>>& cuboids, int idx)
    {
        if(idx == (int)cuboids.size())
            return 0;
        
        int &ret = memory[idx];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(int j = idx + 1 ; j < (int)cuboids.size() ; j++)
            if(canStack(cuboids[idx], cuboids[j]))
                ret = max(ret, LISHeight(cuboids, j));
        
        ret += cuboids[idx][2];
        return ret;
    }
    
    bool canStack(vector<int>& c1, vector<int>& c2)
    {
        if(c1[0] <= c2[0] && c1[1] <= c2[1] && c1[2] <= c2[2])
            return true;
        return false;
    }
};