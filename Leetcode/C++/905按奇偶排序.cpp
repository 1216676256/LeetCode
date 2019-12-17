class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.empty())
            return {};
        int n = A.size();
        int p = 0;
        int q = n - 1;
        while(p < q){
            //cout<<"AAA"<< (A[p]&1) <<endl;
            while(p < n && !(A[p] & 1)) //p�������޼Ӱ�  �ϸ�    &�����ȼ���ô����
                p++;
            while(q >=0 && (A[q] & 1))  //�����漰�����ȼ�˳��  ���Ǽ�һ������Ϊ��
                q--;
            //cout<<p<<"  "<<q<<endl;
            if(p < q){
                swap(A[p], A[q]);
                p++;
                q--;
            }
        }
        return A;
    }
};

/**
    1.   ˫ָ�뷨
         p  Ϊ  ��ߵ�һ����Ϊż�����±�
         q  Ϊ  �ұߵ�һ����Ϊ�������±�   
         ���߽���
         
         ��������:
          [1,3]    �±�Խ�磬û�м��
          
          [0,1,2]  ���[2,1,0]   Ԥ��[0,2,1]
*/