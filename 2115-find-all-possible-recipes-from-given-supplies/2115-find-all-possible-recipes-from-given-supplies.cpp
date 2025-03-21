class Solution {
public:
    /**
     * Approach:
     * - Model the problem as a **graph** where:
     *   - Each **ingredient** is a node.
     *   - A directed edge exists from an **ingredient** to a **recipe** that requires it.
     * - Use **topological sorting (Kahn's algorithm)**:
     *   1. Construct a graph where each recipe depends on its ingredients.
     *   2. Maintain an **in-degree** map to track how many ingredients each recipe needs.
     *   3. Start with available **supplies** and process them using BFS.
     *   4. If all ingredients of a recipe are available, add it to the queue.
     *   5. Continue until all possible recipes are processed.
     *
     * Complexity Analysis:
     * - **Time Complexity**: O(R + I + S), where:
     *   - `R` is the number of recipes.
     *   - `I` is the total number of ingredients across all recipes.
     *   - `S` is the number of supplies.
     *   - We iterate over ingredients to build the graph and process each node once.
     * - **Space Complexity**: O(R + I + S), used for the graph, in-degree map, and queue.
     */
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        int n = recipes.size();
        unordered_map<string, vector<string>> graph; // Ingredient -> List of recipes dependent on it
        unordered_map<string, int> inorder; // Recipe -> Number of ingredients needed
        unordered_set<string> recipesHashSet(recipes.begin(), recipes.end()); // Quick lookup for recipes
        queue<string> ready; // Stores ingredients that are currently available

        // Build the dependency graph and in-degree map
        for (int i = 0; i < n; ++i) 
        {
            for (string ingredient : ingredients[i]) 
            {
                graph[ingredient].push_back(recipes[i]); // Ingredient is required for the recipe
                ++inorder[recipes[i]]; // Increase the number of missing ingredients for the recipe
            }
        }

        // Initialize the queue with all available supplies
        for (string supply : supplies) 
        {
            ready.push(supply);
        }

        vector<string> result;
        // Process available ingredients using BFS (Kahn's algorithm)
        while (!ready.empty()) 
        {
            string cur = ready.front();
            ready.pop();

            if (recipesHashSet.count(cur)) // If current ingredient is a recipe, add to result
                result.push_back(cur);

            // Reduce in-degree for dependent recipes and push them to the queue if all ingredients are available
            for (string neighbour : graph[cur]) 
            {
                if (--inorder[neighbour] == 0) 
                    ready.push(neighbour);
            }
        }

        return result;
    }
};
