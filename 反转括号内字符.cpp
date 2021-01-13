/*leetcode:1190
����һ���ַ��� s��������СдӢ����ĸ�����ţ���
���㰴�մ������ڵ����˳����㷴תÿ��ƥ�������е��ַ��������������յĽ����
*/
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> sta;
        string str;
        for(auto &c : s) {
            if(c == '(') {
                sta.push(str);
                str = "";
            }
            else if(c == ')') {
                reverse(str.begin(),str.end());
                str = sta.top() + str;
                sta.pop();
            }
            else {
                str += c;
            }
        }
        return str;
    }
};
