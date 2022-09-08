class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> result;
        for (int ast : asteroids)
        {
            bool is_exploded = false;
            while (!result.empty() && ast < 0 && result.back() > 0)
            {
                if (result.back() < -ast)
                {
                    result.pop_back();
                    continue;
                }
                else if (result.back() == -ast)
                    result.pop_back();

                is_exploded = true;
                break;
            }
            if (!is_exploded)
                result.push_back(ast);
        }

        return result;
    }
};