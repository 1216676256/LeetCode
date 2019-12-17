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
            return dp[status] = 1;  //对这次的人来说是赢的   没问题.
        } //感觉这里错了
        for(int i = mx; i >= 1; i--){
            if(vis[i])  continue;
            if(sum + i >= target){
                return dp[status] = 1;
            }
        }   //加了这个循环就对了....
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
    
    
    第二次尝试
        还是调试了好久啊 
        dp[status] 想清楚到底什么意思 
            status 包含拿了哪些东西（次数啥的)    能不能赢
*/