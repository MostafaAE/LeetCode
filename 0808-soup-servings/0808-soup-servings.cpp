class Solution {
private:
    unordered_map<int, unordered_map<int, double>> memory;

    double calculateDP(int a, int b) 
    {
        if (a <= 0 && b <= 0) 
            return 0.5; // both empty at same time
        if (a <= 0) 
            return 1.0;           // A empty first
        if (b <= 0) 
            return 0.0;           // B empty first

        if (memory[a].count(b)) 
            return memory[a][b];

        memory[a][b] = 0.25 * (
            calculateDP(a - 4, b) +
            calculateDP(a - 3, b - 1) +
            calculateDP(a - 2, b - 2) +
            calculateDP(a - 1, b - 3)
        );

        return memory[a][b];
    }

public:
    double soupServings(int n) 
    {
        if (n > 5000) 
            return 1.0; // optimization for large n

        // convert to servings of 25 ml
        int m = ceil(n / 25.0); 

        return calculateDP(m, m);
    }
};