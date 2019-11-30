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
            while(p < n && !(A[p] & 1)) //p不能无限加啊  老哥    &的优先级这么低吗
                p++;
            while(q >=0 && (A[q] & 1))  //这里涉及到优先级顺序  还是加一下括号为妙
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
    1.   双指针法
         p  为  左边第一个不为偶数的下标
         q  为  右边第一个不为奇数的下标   
         两者交换
         
         错误样例:
          [1,3]    下标越界，没有检查
          
          [0,1,2]  输出[2,1,0]   预期[0,2,1]
*/