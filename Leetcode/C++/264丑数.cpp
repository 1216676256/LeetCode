class Solution {
public:
    int nthUglyNumber(int n) {
        
    }
    
};
/**
    1.ûʲô˼·
        һ���������տ��Ա�ʾΪ  2^a * 3^b * 5^c
        ��ȴ���ü���������
        
    2.
      1
      2 3 5
      4 6 10  ==�� 3 4 5 6 10
      6 9 15 ==��  4 5 6 9 10
      8 12 20 ==�� 5 6 8 9 10 12 20
      10 15 25 ==��   5 6 8 10 12 15 20 25
      
     3. ��������
      
      int  �����ֵ  2^32 -1
      �������32��  �ʿ��Ա���  ������г�����������
          vector<int>num;
            int mx = 0x7FFFFFFF;
            for(long a = 1; a <= mx; a *= 2){
                for(long b = a; b <= mx; b *= 3){
                    for(long c = b; c <= mx; c *= 5)
                        num.push_back(c);
                }
            }
            sort(num.begin(), num.end());
            return num[n - 1];
            
    4.
*/