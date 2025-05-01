class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) 
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 1, right = min((int)workers.size(), (int)tasks.size()), ans = 0;
        while (left <= right) 
        {
            int mid = (left + right) / 2;
            if (canAssign(tasks, workers, pills, strength, mid)) 
            {
                ans = mid;
                left = mid + 1;
            } 
            else 
            {
                right = mid - 1;
            }
        }
        return ans;
    }

private:
    bool canAssign(const vector<int>& tasks, const vector<int>& workers, int pills, int strength, int mid) 
    {
        int p = pills;
        multiset<int> ws;

        for (int i = workers.size() - mid; i < workers.size(); ++i) 
        {
            ws.insert(workers[i]);
        }

        for (int i = mid - 1; i >= 0; --i) 
        {
            auto it = prev(ws.end());
            if (*it >= tasks[i]) 
            {
                ws.erase(it);
            } 
            else 
            {
                if (p == 0) 
                {
                    return false;
                }

                auto rep = ws.lower_bound(tasks[i] - strength);
                if (rep == ws.end()) 
                {
                    return false;
                }

                ws.erase(rep);
                --p;
            }
        }
        return true;
    }
};
