class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {find(nums,target,false), find(nums, target, true)};
    }
    
    int find(vector<int>&nums, int target,bool flag){
        int len = nums.size();
        if(len == 0)
            return -1;
        int ans = !flag ? len : -1;
        int L = 0;
        int R = len - 1;
        while(L <= R){
            int mid = (L + R) >>1;
            if(nums[mid] > target){
                R = mid - 1;
            }
            else if(nums[mid] < target){
                L = mid + 1;
            }
            else{
                if(!flag)
                    ans = min(ans, mid);
                else ans = max(ans,mid);
                if(!flag)   //找最左边的
                    R = mid -1;
                else  //最右边的
                    L = mid + 1;
            }
        }
        return ans == len ? -1 :ans;
    }
};
/**
  简单的二分查找  边界的变形
  
  [2,2]
  2
*/