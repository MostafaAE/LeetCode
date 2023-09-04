#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;


////////////////////////////

const int MAXN = 100002;
typedef long long ll;
int Log[MAXN];
ll stable[MAXN][17];
ll arr[MAXN];
int n;

void build() {
	int cnt = -1;
	for (int i = 0; i < n; i++) {
		if (!((i + 1) & i))
			cnt++;
		stable[i][0] = i;
		Log[i + 1] = cnt;
	}
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; (i + (1 << j)) <= n; i++) {
			int a = stable[i][j - 1];
			int b = stable[i + (1 << (j - 1))][j - 1];
			stable[i][j] = ((arr[a] < arr[b]) ? a : b);
		}
	}
}

// Return minimum index in this range in O(n)
int getMinIdx_slow(int l, int r) {
	int minIdx = l;

	for (int i = l + 1; i <= r; i++)
		if (arr[minIdx] > arr[i])
			minIdx = i;

	return minIdx;
}

// This is well known sub-problem (Range Minimum Query (RMQ))
// Can be solved in O(logn)
int getMinIdx(int st, int en) {
	int L = Log[en - st + 1];
	int a = stable[st][L], b = stable[en - (1 << L) + 1][L];
	return ((arr[a] < arr[b]) ? a : b);
}

void prepare(vector<int> &heights) {
	n = heights.size();
	for (int i = 0; i < n; ++i)
		arr[i] = heights[i];

	build();
}

////////////////////////////

int getMaxArea(vector<int> &heights, int l, int r) {
    
    if(l > r)
        return 0;

	int min_idx = getMinIdx(l, r);
    
    int maxArea = heights[min_idx] * (r-l+1);
    
    int leftMaxArea = getMaxArea(heights, l, min_idx - 1);
    int rightMaxArea = getMaxArea(heights, min_idx + 1 , r);
    
    return max(maxArea, max(leftMaxArea, rightMaxArea));
}

class Solution {
public:
	int largestRectangleArea(vector<int> &heights) {
		prepare(heights);

		return getMaxArea(heights, 0, heights.size() - 1);
	}

};