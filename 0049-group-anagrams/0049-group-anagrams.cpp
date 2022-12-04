class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(m*nlogn) where m is number of words, and n is average length of a word
    * Space Complexity : O(m*n)
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> result;
        int idx{};
        unordered_map<string, int> anagramToIdx;
        
        for(int i = 0 ; i < (int)strs.size() ; i++)
        {
            string cpy = strs[i];
            // O(nlogn)
            sort(cpy.begin(), cpy.end());
            
            if(!anagramToIdx.count(cpy))
            {
                result.push_back(vector<string>{strs[i]});
                anagramToIdx[cpy] = idx++;
            }
            else
                result[anagramToIdx[cpy]].push_back(strs[i]);
        }
        
        return result;
    }
};