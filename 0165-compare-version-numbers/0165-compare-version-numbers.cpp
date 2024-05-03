class Solution {
public:
    /*
    * Approach:
    * - Iterate through both version strings simultaneously.
    * - Extract the numbers between '.' characters and compare them.
    * - If a number in the first version is smaller than the corresponding number in the second version, return -1.
    * - If a number in the first version is larger than the corresponding number in the second version, return 1.
    * - If both versions are equal up to the end, return 0.
    *
    * Complexity:
    * - Time Complexity: O(max(n, m)), where n is the length of version1 and m is the length of version2.
    * - Space Complexity: O(1)
    */
    int compareVersion(string version1, string version2) 
    {
        int size1 = version1.size(), size2 = version2.size();
        int idx1{}, idx2{}, num1{}, num2{};
        
        while(idx1 < size1 || idx2 < size2)
        {
            while(idx1 < size1 && version1[idx1] != '.')
                num1 = num1 * 10 + (version1[idx1]-'0'), ++idx1;
            
            while(idx2 < size2 && version2[idx2] != '.')
                num2 = num2 * 10 + (version2[idx2]-'0'), ++idx2;

            if(num1 < num2)
                return -1;
            else if(num1 > num2)
                return 1;
            
            num1 = 0, num2 = 0;
            ++idx1, ++idx2;
        }

        return 0;
    }
};