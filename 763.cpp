//Leetcode763:�ַ��� S ��Сд��ĸ��ɡ�����Ҫ������ַ�������Ϊ�����ܶ��Ƭ�Σ�ͬһ����ĸֻ����������е�һ��Ƭ�Ρ�����һ����ʾÿ���ַ���Ƭ�εĳ��ȵ��б�
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int size=S.size();
        int last[26];//�洢ÿ����ĸ���һ�γ��ֵ�λ��
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