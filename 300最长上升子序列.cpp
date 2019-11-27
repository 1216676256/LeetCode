class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int>ans;
        int mx = nums[0];
        ans.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > ans[ans.size() - 1]){
                mx = max(mx, nums[i]);
                ans.push_back(nums[i]);
            }
            else {
                //cout<<i<<endl;
                int ind = binarySearch(ans, nums[i]);
               // cout<<"CCC  "<<ind<<endl;
                ans[ind] = nums[i];
            }
        }
        return ans.size();
    }
    int  binarySearch(vector<int>& a, int target){
        if(a.empty())
            return 0;
        int L = 0;
        int R = a.size() - 1;
        int res = R;
        while(L <= R){
            int mid = (L + R) >>1;
            if(a[mid] < target){
                L = mid + 1;
            }
            else if(a[mid] >=target){
                res = min(res, mid);
                R = mid - 1;
            }
        }
        return res;
    }
};

/**
   10 9 2 5 3 7 101 18
   
   10
   9
   2 5
   2 3
   2 3 7
   2 3 7 101
   2 3 7 18
   
   
   
   binarySearch  
   1 2 3 4 5 6 7 8 9     5.5
   
   
   错误样例
   [2,2]
   1     要求的是上升  不是    不减子序列
*/