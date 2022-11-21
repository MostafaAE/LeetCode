// O(bits count)
int countBits(int n)
{
    int count{};
    while(n)
    {
        // remove the last bit and so on
        n &= (n-1);
        count++;
    }
    return count;
}

bool compare(int a, int b)
{
    int countA = countBits(a);
    int countB = countBits(b);

    if(countA == countB)
        return a < b;
    return countA < countB;  
}

class Solution {
public:
    /* 
    * Approach:
    * count the number of 1's in the binary representation of each integer, sort by the number of 1's and value
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1)
    */
    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};