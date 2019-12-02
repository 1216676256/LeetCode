class Solution {
public:
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
                nstatus = status | (1<< (i- 1));    //这里不是左移  where - 1
                dp[status] = 1;
                return true;
            }
        }
       // cout<<"循环结束"<<endl;
        for(int i = 1; i <= mx; ++i){
            int nind = i;
            if(vis[nind])  continue;
            vis[nind] = true;
            bool flag = dfs(sum + nind, mx, target, nind,where + 1,status | (1<< (nind - 1)));
            vis[nind] = false;   //这里没改成nind
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
};


/**
    1.一开始没思路  后来突然就有灵感了  贪心
    
    当前状态   玩家已经知道目前拿了多少了（和）   还有哪些数可以拿(知道min，max),
    双指针维护一下
    要是他拿max 都赢不了，那他肯定拿最小的
    
    上述有待改进
    10 14
    不能 取 1 2 3 10  这样就是后手赢了
    应该取 3  x  y   y总有办法 让和 >=14
       所以没啥思路了
       

    2.   可以选的数也就就20个    1024 * 1024 (错了 20!) 在减枝  问题应该不大
    
    超时样例:  
        18
        79     再加一个 记忆化  状态   1<< mx
    
    
    错误样例
        10
        40
         经过几次的debug  终于过了
*/