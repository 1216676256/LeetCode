class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 0)
            return false;
        if(k == 0){
            int flag = 0;
            for(int a : nums){
                if(a == 0){
                    flag++;
                    if(flag == 2)
                        return true;
                }
                else
                    flag = 0;
            }
            return false;
            
        }
            
        map<int, int>mp;
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum += nums[i];
            if(sum % k == 0 && i >=1)
                return true;
            int cnt = sum % k;
            if(mp[cnt] != 0){
                if(i + 1 - mp[cnt] >=2)
                    return true;
            }
            else{
                mp[cnt] = i + 1;
            }
        }
        return false;
    }
};

/**
    1.   感觉是数学题
    
     x -->  x % k = a;
x + n *k -->       = a;



通不过的样例
 [0,0]
 0
 
 [1,2,3]
 5

*/