//986:����������һЩ ������ ��ɵ��б�ÿ�������б��ǳɶԲ��ཻ�ģ������Ѿ����򡣷��������������б�Ľ�����
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int AIndex = 0;   // A���������
        int BIndex = 0;   // B���������
        vector<vector<int>> result; //�洢���ֵ
        result.reserve(A.size() + B.size()); //һ�δ����㹻�����������ݵĿռ�
        while(AIndex != A.size() && BIndex != B.size()){ //��A,B�ķ���������û��������Χʱ
            vector<int> A_one = A[AIndex]; //�õ�A�ĵ�ǰ����
            vector<int> B_one = B[BIndex]; //�õ�B�ĵ�ǰ����
            
            int leftValue = max(A_one[0],B_one[0]); //�õ�������ǰ�������ֵ�Ľϴ�ֵ 
            int rightValue = min(A_one[1],B_one[1]); //�õ�������ǰ�������ֵ�Ľ�Сֵ 
            
            if (leftValue <= rightValue) //�ж��Ƿ���ڽ�������
                result.push_back({leftValue,rightValue});
            
            //�������������������������
            if (A_one[1] < B_one[1]) 
                AIndex++;
            else if(A_one[1] == B_one[1])
                {AIndex ++; BIndex ++;}
            else
                BIndex++;        
        }
        return result;        
    }
};
