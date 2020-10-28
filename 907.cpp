// ans：数组A[]的连续子数组最小值之和,ans=dp[0]+dp[1]+...+dp[n-1]
// dp[i]：以A[i]结尾的子数组的最小值之和，这是重点，以A[i]为结尾，意思就是 A[1,....,i],A[2,....,i]...A[i-1,i],就是线性的。
// dp[i]=dp[i-1]+A[i]-(修正值offset)
//如果是单调递增栈的话，A[i]作为最大值，只影响最后一个组合就是本身，A[I]的最小值才为A【I】.所以直接加上就好 
// 但是如果A[i] < A[stack.top()]的话，意味着本来以A[stack.top()]为最小值的(栈顶保存的下标-栈顶第二个元素保存的下标)这些元素
//发现自己被骗了，应该以A[i]为最小值，所以
// 对A[i]之前的每个段{offset+=(A[栈顶保存的下标]-A[i])*(栈顶保存的下标-栈顶第二个元素保存的下标)}
// 单调增栈st：从st[i-1]+1一直到st[i]代表一个段，且该段的最小值恰是A[st[i]]
//举个例子，对弈[1,3,2]来说：
//第一次1入栈，dp[0] = 1，以1结尾的；ans = dp[0] = 1;这时候只有一种情况就是{1}
//第二次3 > 1;dp[1] = dp[0] + A[1];这时候以3结尾的有两种情况{1,3}，{3}，所以最小值之和是 dp[1] = 1 + 3 = 4;
//第三次 2 < 3;dp[2] = {1,3,2} , {3,2},{2};然而dp[1] = {1,3}，{3}；所以2的出现，让{3} ——> {3,2}，这里的最小值成了2；
// 所以要减去1； dp[2] = dp[1] + A[i] - 1 = 5;
//所以ans = 1 + 4 + 5 =10
class Solution {
public:
   int sumSubarrayMins(vector<int>& A) {
       const int BASE = 1e9 + 7;
       stack<int> st;
       int ans = 0, sum = 0; // sum：以A[i]结尾的子数组的ans，相当于dp[i]
       for (int i = 0; i < A.size(); ++i) {
           while (!st.empty() && A[st.top()] >= A[i]) {
               int top = st.top(); st.pop();
               int new_top = st.empty() ? -1 : st.top();
               sum += ((A[i] - A[top]) % BASE * (top - new_top) % BASE);
           }
           sum = (sum + A[i]) % BASE;
           ans = (ans + sum) % BASE;
           st.push(i);
       }
       return ans % BASE;
   }
};
