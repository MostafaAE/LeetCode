class Solution {
public:
    /**
     * Approach:
     * - Given that this is a star graph, the center node is connected to all other nodes.
     * - Therefore, the center node must appear in any two edges.
     * - So we can check the first node of the first edge against both nodes of the second edge.
     * - If it matches either node, it is the center. Otherwise, the second node of the first edge is the center.
     *
     * Complexity:
     * - Time Complexity: O(1)
     * - Space Complexity: O(1)
     */
    int findCenter(vector<vector<int>>& edges) 
    {
        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            ? edges[0][0] 
            : edges[0][1];
    }
};
