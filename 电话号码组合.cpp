//17����ĸ���
class Solution {
private:
	const vector<string> alpmap = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> ans;//�洢�������
	string temp;//��¼ÿһ�����
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