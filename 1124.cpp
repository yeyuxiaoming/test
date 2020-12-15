/*1124:表现时间良好的最长时间段
给你一份工作时间表?hours，上面记录着某一位员工每天的工作小时数。
我们认为当员工一天中的工作小时数大于?8 小时的时候，那么这一天就是「劳累的一天」。
所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。
请你返回「表现良好时间段」的最大长度。*/
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();

        unordered_map<int, int> count;
        int cur = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (hours[i] > 8) {
                cur++;
            } else {
                cur--;
            }
            if (cur > 0) res = i + 1;
            else {
                if (count.count(cur-1) > 0) res = max(res, i - count[cur-1]);
                if (count.count(cur) < 1) count[cur] = i;
            }
        }
        return res;

    }
};
