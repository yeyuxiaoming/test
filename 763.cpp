//Leetcode763:字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int size=S.size();
        int last[26];//存储每个字母最后一次出现的位置
        for(int i=0;i<size;i++){
            last[S[i]-'a']=i;
        }
        vector<int> partition;
        int star=0,end=0;
        for(int i=0;i<size;i++){
            end=max(end,last[S[i]-'a']);
            if(i==end){
                partition.push_back(end-star+1);
                star=end+1;
            }
        }
        return partition;
    }
};