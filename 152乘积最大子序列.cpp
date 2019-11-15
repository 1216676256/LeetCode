class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        long long mi = nums[0];
        long long  mx = nums[0];
        long long ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            long long t1 =  max((long long)nums[i], max(mx * nums[i],mi* nums[i]));
            long long  t2 =  min((long long)nums[i], min(mx * nums[i], mi * nums[i]));
            mx = t1 ;
            mi = t2 ;
           // cout<<mx <<" "<<mi<<endl;
            ans = max(ans,mx);
        }
        return ans;
    }
};
/**
    1.  ö�������յ� O(n^2)  �ټ��ϼ���˻� O(n^3)
    
    2. dp[i]  ��ʾ ��i����ѡ������ģ����������˻�
        dp[i + 1] = max(nums[i], dp[i] * nums[i]);
        ֻ��ֱ������֪���Բ���...
        �ԵĻ�����������Ż�
        [-2,3,-4]  ����Ͳ�����
        
        ��¼���˻�����С�˻�
        ��;���ᱬint....
*/