class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)  return 0;
        int tmp = nums[0];
        int cnt  = 1;
        for(int i = 1; i< nums.size(); i++){
            if(nums[i] != tmp){
                tmp = nums[i];
                cnt++;
            }
            else{
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return cnt;
    }
};