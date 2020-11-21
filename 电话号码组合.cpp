//17：字母组合
class Solution {
private:
	const vector<string> alpmap = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> ans;//存储所有组合
	string temp;//记录每一种组合
	void DFS(string& digits, int n)
	{
		if (n == digits.size())
			ans.emplace_back(temp);
		else
		{
			string s = alpmap[digits[n] - '2'];
			for (auto x : s)
			{
				temp.push_back(x);
				DFS(digits, n + 1);
				temp.pop_back();
			}
		}
		return;
	}
public:
	vector<string> letterCombinations(string digits)
	{
		if (!digits.size())
			return {};
		DFS(digits, 0);
		return ans;
	}
};