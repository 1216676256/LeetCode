class Solution {
public:
    string pushDominoes(string dominoes) {
        if(dominoes.empty())
            return "";
        int len = dominoes.size();
        int L = -1;
        int R = -1;
        int R2 = -1;
        int ind  = -1;
        for(int i = 0; i < len; ++i){
            //cout<<L<<"   "<<R<<"  ";
            if(dominoes[i] == 'L')
                L = i;
            else if(dominoes[i] == 'R'){
                if(R == -1)
                    R = i;
                else R2 = i;
            }
            //cout<<L<<"   AAA   "<<R<<endl;
            if(L !=-1 && R == -1){
                //cout<<"  ZZZZ "<<endl;
                for(int j = L - 1; j > ind; --j){
                    dominoes[j] = 'L';
                }
                ind = L;
                L = -1;
            }
            else if(L != -1 && R != -1){
               // cout<<"  XXX  "<<endl;
                int s = R;
                int t = L;
                ind = L;
                while(s < t){
                    dominoes[s++] = 'R';
                    dominoes[t--] = 'L';
                }
                L = -1;
                R = -1;
            }
            else if(R != -1 && R2 != -1){
                //cout<<"  CCC  "<<endl;
                ind = R2 - 1;
                while(R < R2){
                    dominoes[R++] = 'R';
                }
                R = R2;
                R2 = -1;
            }
        }
        if(R != -1){
            for(int i = R + 1; i < len; i++)
                dominoes[i] = 'R';
        }
        return dominoes;
    }
};

/**
    1.不是动态规划的方法
        遍历
        找到不是.的
            先是L  就--  赋值  （要记录最大操作的下标）
            
            若是R  找下一个
                R  第一个R可以操作  第二个变成第一个
                L  往中间遍历
                没有   ++ 遍历
*/