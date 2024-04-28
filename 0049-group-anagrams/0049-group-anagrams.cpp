class Solution {
public:
    /* 
    * Approach:
    * Iterate through each string in the input vector.
    * For each string, sort its characters alphabetically. This will make anagrams have the same sorted representation.
    * Use an unordered_map to store the sorted representation of each anagram and its corresponding index in the result vector.
    * If the sorted representation is not found in the map, create a new entry in the result vector and map.
    * Otherwise, append the string to the corresponding group in the result vector.
    *
    * Complexity:
    * Time Complexity : O(m*nlogn) where m is number of words, and n is average length of a word
    * Space Complexity : O(m*n)
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int idx{};
        vector<vector<string>> result;
        unordered_map<string, int> anagramToIdx;
        
        for(auto &str : strs)
        {
            string cpy = str;
            // O(nlogn)
            sort(cpy.begin(), cpy.end());
            
            if(!anagramToIdx.count(cpy))
            {
                result.push_back(vector<string>{str});
                anagramToIdx[cpy] = idx++;
            }
            else
                result[anagramToIdx[cpy]].push_back(str);
        }
        
        return result;
    }
};