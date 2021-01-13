/*leetcode:1190
给出一个字符串 s（仅含有小写英文字母和括号）。
请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。
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
