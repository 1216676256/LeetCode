class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long sum = 0; //��int  5 * 10^10
        for(int a : nums)
            sum += a;
        if(sum <= threshold)
            return 1;
        int len = nums.size();
        if(len > threshold)
            return -1;
        int L = 1;
        int R = 0x7FFFFFFF;
        int ans = R;
        while(L <= R){
            
            int mid = L + (R - L) / 2;
           // cout<<"AAAA  "<<L<<"  "<<R<<"  "<<mid<<" "<<getSum(nums, mid)<<endl;
            if(getSum(nums, mid) <= threshold){
                ans = min(ans, mid);
                R = mid - 1;
            }
            else{
                L = mid + 1;
            }
        }
        return ans;
    }
    
    int getSum(vector<int>& t, int x){
        int sum = 0;
        for(int a : t){
            if(a % x ==0){
                sum += a/x;
            }
            else sum += (a/x) + 1;
        }
        return sum;
    }
};
/**
    1. ����  ���ܱ�֤�����Ե��𣨺�����Ա�֤��   �������漰������.. Ҫע��һ��
    
    N/x   N/(x + 1)  �Ͷ�����
*/  