/*爱丽丝有一手（hand）由整数数组给定的牌。?
现在她想把牌重新排列成组，使得每个组的大小都是 W，且由 W 张连续的牌组成。
如果她可以完成分组就返回 true，否则返回 false。
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
                if(card.back() == cur + 1) sta.push(card.back());//重复的元素加入栈中
                else if (card.back() == cur) {
                    cur--;
                    k++;
                }
                else return false;
                card.pop_back();
            }
            while(!sta.empty()) {//把重复元素加入card中，进行下一次匹配
                card.push_back(sta.top());
                sta.pop();
            }
        }
        return true;
    }
};
