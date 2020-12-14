/*����˿��һ�֣�hand������������������ơ�?
������������������г��飬ʹ��ÿ����Ĵ�С���� W������ W ������������ɡ�
�����������ɷ���ͷ��� true�����򷵻� false��
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if(n % W) return false;
        vector<int> card = hand;
        sort(card.begin(), card.end());
        stack<int> sta;
        int cur;
        for(int i = 0; i < n / W; i++) {
            cur = card.back();
            int k = 0;
            while(k < W) {
                if(card.empty()) return false;
                if(card.back() == cur + 1) sta.push(card.back());//�ظ���Ԫ�ؼ���ջ��
                else if (card.back() == cur) {
                    cur--;
                    k++;
                }
                else return false;
                card.pop_back();
            }
            while(!sta.empty()) {//���ظ�Ԫ�ؼ���card�У�������һ��ƥ��
                card.push_back(sta.top());
                sta.pop();
            }
        }
        return true;
    }
};
