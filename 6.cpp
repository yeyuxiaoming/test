class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool godown = false;
        for(auto &c : s) {
            if(curRow == 0 || curRow == numRows - 1) {
                godown = !godown;
            }
            rows[curRow] += c;
            curRow += godown ? 1 : -1;
        }
        string str;
        for(string r : rows) {
            str += r;
        }
        return str;
    }
};