class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans;
        if(nums.empty())
            return ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n,1);
        //dp[i]   选中（第i个元素为末尾的   符合题意的长度）
        //dp[0] = 1;  //应该初始化成每个都是 1的  
        int mx = 1;
        int ind = 0;
        vector<int>pre(n, -1);
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                //cout<<"AAA"<<endl;
                if(nums[i] % nums[j] == 0){
                    //cout<<i<<"   "<<j<<endl;
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                        if(dp[i] > mx){
                            ind = i;
                            mx = dp[i];
                        }
                    }
                }
            }
        }
        while(ind != -1){
            ans.push_back(nums[ind]);
            ind = pre[ind];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/**
   1.假设数组已经从小到大排好序了
   
       i  j  k  l m n 是满足题意的        2 4 8 16

       j%i==0   k % j==0   ==> k%i ==0            注：这里就可以看出来一个大问题可以分解成一个子问题
       但   j%i ==0   k%i ==0  ,k > j;  推不出   k%j ==0   1 3 7  or  2 4 6 
       
       错误样例:
       [2,3,8,9,27]   输出[2,8]  但应该是[3,9,27]
   
   2.可以看到  答案里面的元素  都是  某个底数的n次方
    vector<int>ans;
        if(nums.empty())
            return ans;
        sort(nums.begin(), nums.end());
        set<int>s;
        for(int a : nums){
            s.insert(a);
        }
        int len = nums.size();
        int mx = nums[len - 1];
        vector<int>tmp;
        for(int i = 1; i <= mx; ++i){      //mx 的话会超时     用len  a[i]的话  有些样例过不了
            long long product = 1;
            tmp.clear();
            for(int j = 0; product <= mx; ++j){
                 if(s.find(product) != s.end()){
                     tmp.push_back(product);
                 }
                if(i == 1)
                    break;
                 product = product * i;
            }
            if(tmp.size() > ans.size())
                ans = tmp;
        }
        return ans;
   
       错误样例
       [3,4,16,8]
       我的输出
       [4,16]  因为我的底数没有比遍历到2
*/