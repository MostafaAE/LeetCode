class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
    {
        int m = score.size(), n = score[0].size();
        vector<pair<int, int>> kthScoreToIndex(m);
        vector<vector<int>> result(m);

        for(int i = 0 ; i < m ; ++i)
        {
            kthScoreToIndex[i] = {score[i][k], i};
        }

        sort(kthScoreToIndex.begin(), kthScoreToIndex.end(), greater<>());

        for(int i = 0 ; i < m ; ++i)
        {
            int index = kthScoreToIndex[i].second;
            result[i] = score[index];
        }

        return result;
    }
};