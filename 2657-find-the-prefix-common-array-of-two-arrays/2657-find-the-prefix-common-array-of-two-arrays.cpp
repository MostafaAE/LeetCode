class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n = A.size(), count{};
        unordered_set<int> hashSet;
        vector<int> result(n, 0);

        for(int i = 0 ; i < n ; ++i)
        {
            if(!hashSet.insert(A[i]).second)
                ++count;

            if(!hashSet.insert(B[i]).second)
                ++count;
            
            result[i] = count;
        }

        return result;
    }
};