//给你一个整数数组?arr?和一个整数?difference，请你找出?arr?中所有相邻元素之间的差等于给定?difference?的等差子序列，并返回其中最长的等差子序列的长度。

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
       int n = arr.size();
	if (n == 0) { return 0; }
	vector<int> dp(n, 1);
	dp[0] = 1;
	int MAX = 1;
	unordered_map<int, vector<int>> intMap;
	for (int i = 0; i < n; i++) {
		intMap[arr[i]].push_back(i);
	}

	for (int i = 1; i < n; i++) {
		if (intMap.count(arr[i] - difference) ) {
			for (auto iter = intMap[arr[i] - difference].begin(); iter != intMap[arr[i] - difference].end(); iter++) {
				int index = *iter;
				if (index < i) {
					dp[i] = max(dp[i], dp[index] + 1);
				}
			}
		}
		MAX = max(MAX, dp[i]);
	}

	return MAX;
    }
};
