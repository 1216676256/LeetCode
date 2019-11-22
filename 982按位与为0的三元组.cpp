class Solution {
public:
    int countTriplets(vector<int>& A) {
        int len = A.size();
        int cnt[1<<16 +5];
        memset(cnt,0,sizeof(cnt));
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                cnt[A[i] & A[j]]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < (1<<16 + 5); i++){
            if(cnt[i] == 0)
                continue;
            if(i == 0){
                ans += cnt[i] * len;
                //cout<<ans<<"  AA "<<endl;
                continue;
            }
            else{
                for(int j = 0; j < len; j++){
                    if((i & A[j]) == 0){
                        ans += cnt[i];
                        //cout<<ans<<endl;
                    }
                }
            }
        }
        return ans;
    }
};

/**
  1. ����  O��n^3��
  
  2.  ���������������Ǵ�����   ����λ�ٱ���һ��
  2^16 =16*1024
*/