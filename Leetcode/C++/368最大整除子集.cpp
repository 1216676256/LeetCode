class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans;
        if(nums.empty())
            return ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n,1);
        //dp[i]   ѡ�У���i��Ԫ��Ϊĩβ��   ��������ĳ��ȣ�
        //dp[0] = 1;  //Ӧ�ó�ʼ����ÿ������ 1��  
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
   1.���������Ѿ���С�����ź�����
   
       i  j  k  l m n �����������        2 4 8 16

       j%i==0   k % j==0   ==> k%i ==0            ע������Ϳ��Կ�����һ����������Էֽ��һ��������
       ��   j%i ==0   k%i ==0  ,k > j;  �Ʋ���   k%j ==0   1 3 7  or  2 4 6 
       
       ��������:
       [2,3,8,9,27]   ���[2,8]  ��Ӧ����[3,9,27]
   
   2.���Կ���  �������Ԫ��  ����  ĳ��������n�η�
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
        for(int i = 1; i <= mx; ++i){      //mx �Ļ��ᳬʱ     ��len  a[i]�Ļ�  ��Щ����������
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
   
       ��������
       [3,4,16,8]
       �ҵ����
       [4,16]  ��Ϊ�ҵĵ���û�бȱ�����2
*/