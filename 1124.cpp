/*1124:����ʱ�����õ��ʱ���
����һ�ݹ���ʱ���?hours�������¼��ĳһλԱ��ÿ��Ĺ���Сʱ����
������Ϊ��Ա��һ���еĹ���Сʱ������?8 Сʱ��ʱ����ô��һ����ǡ����۵�һ�졹��
��ν���������õ�ʱ��Ρ�����ζ�����ʱ���ڣ������۵����������ϸ� ���ڡ������۵���������
���㷵�ء���������ʱ��Ρ�����󳤶ȡ�*/
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
