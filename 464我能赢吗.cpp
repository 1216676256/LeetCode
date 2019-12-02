class Solution {
public:
    vector<bool>vis;
    vector<int>dp;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int n = maxChoosableInteger;
        if(n * (1 + n) / 2 < desiredTotal)
            return false;
        vis.resize(n + 1, false);
        dp.resize((1 << n), -1); 
        bool ans =  dfs(0, 0, desiredTotal, n,0);
        return ans;
    }
    
    bool dfs(int sum, int status,int target,int mx,int ind){
        if(dp[status] != -1)
            return dp[status];
        if(sum >= target){
            return dp[status] = 1;  //����ε�����˵��Ӯ��   û����.
        } //�о��������
        for(int i = mx; i >= 1; i--){
            if(vis[i])  continue;
            if(sum + i >= target){
                return dp[status] = 1;
            }
        }   //�������ѭ���Ͷ���....
        for(int i = 1; i <= mx; ++i){
            if(vis[i])   continue;
            vis[i] = true;
            bool flag = dfs(sum + i, status | (1 << (i - 1)), target, mx,ind + 1);
            vis[i] = false;
            if(!flag){
                return dp[status] = true; 
            }
        }
        return dp[status] = false;
    }
};


/**
    1.һ��ʼû˼·  ����ͻȻ���������  ̰��
    
    ��ǰ״̬   ����Ѿ�֪��Ŀǰ���˶����ˣ��ͣ�   ������Щ��������(֪��min��max),
    ˫ָ��ά��һ��
    Ҫ������max ��Ӯ���ˣ������϶�����С��
    
    �����д��Ľ�
    10 14
    ���� ȡ 1 2 3 10  �������Ǻ���Ӯ��
    Ӧ��ȡ 3  x  y   y���а취 �ú� >=14
       ����ûɶ˼·��
       

    2.   ����ѡ����Ҳ�;�20��    1024 * 1024 (���� 20!) �ڼ�֦  ����Ӧ�ò���
    
    ��ʱ����:  
        18
        79     �ټ�һ�� ���仯  ״̬   1<< mx
    
    
    ��������
        10
        40
         �������ε�debug  ���ڹ���
         vector<bool>vis;
    vector<int>dp;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int n = maxChoosableInteger;
        if((n + 1) * n / 2 < desiredTotal)
            return false;
        vis.resize(n + 1, false);
        dp.resize(1<<n, -1);
        return dfs(0, n, desiredTotal,0,1,0);
    }
    
    bool dfs(int sum, int mx, int target, int ind,int where, int status){
        //cout<<where<<"   "<<status<<endl;
        int nstatus;
        if(dp[status] != -1)
            return dp[status];
        for(int i = mx; i >=1; i--){   //i > 0
            //cout<<"xunhuan"<<endl;
            if(vis[i]) continue;
            if(sum + i >= target){
                nstatus = status | (1<< (i- 1));    //���ﲻ������  where - 1
                dp[status] = 1;
                return true;
            }
        }
       // cout<<"ѭ������"<<endl;
        for(int i = 1; i <= mx; ++i){
            int nind = i;
            if(vis[nind])  continue;
            vis[nind] = true;
            bool flag = dfs(sum + nind, mx, target, nind,where + 1,status | (1<< (nind - 1)));
            vis[nind] = false;   //����û�ĳ�nind
            if(!flag){
                dp[status] = true;
                //cout<<"AAA   "<<status<<endl;
                return true;
            }
        }
        dp[status] = false;
        //cout<<"BBBB   "<<status<<endl;
        return false;
    }
    
    
    �ڶ��γ���
        ���ǵ����˺þð� 
        dp[status] ���������ʲô��˼ 
            status ����������Щ����������ɶ��)    �ܲ���Ӯ
*/