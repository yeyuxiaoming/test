//372:你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
class Solution {
public:
	int qpow(int a, int b, int m)
	{
		int res = 1;
		while (b)
		{
			if (b & 1)res = (res * a) % m;
			a = (a % m) * (a % m) % m;
			b >>= 1;
		}
		return res;
	}
	int superPow(int a, vector<int>& b) {
		int n = 0, res = 1;
		for (int x : b) res = qpow(res,10,1337) * qpow(a, x, 1337) % 1337;
		return res;
	}
};
