class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int ans = nums[0];
        int cnt = 1;
        for(int i = 1; i < len; i++){
            if(cnt == 0){
                ans = nums[i];
                cnt++;
                continue;
            }
            if(ans == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
            
        }
        return ans;
    }
};
/**
    1.���α���
    
    2.�ӼӼ����Ĳ���
*/