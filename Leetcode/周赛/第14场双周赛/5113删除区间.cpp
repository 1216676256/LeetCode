class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int L = toBeRemoved[0];
        int R = toBeRemoved[1];
        vector<vector<int>>ans;
        for(vector<int> a : intervals){
            if(L <= a[0] && a[1] <= R)   //两端都在里面
                continue;
            else if((L <=  a[0] && a[0] <= R) || (L <= a[1] && a[1] <= R)){  //只有一端在里面{
                if(a[0] < L){
                    ans.push_back({a[0], L});
                }
                else if(a[1] > R){
                    ans.push_back({R, a[1]});
                }
            }
            else  if(L >= a[0] && R <= a[1]){
                //toBe的区间别包含了
                ans.push_back({a[0], L});
                ans.push_back({R, a[1]});
            }
            else{
                //
                ans.push_back(a);
            }
        }
        return ans;
    }
};


/**
  1. 和合并区间很像   画一下图就明白了
        (L <=  l[i] && l[i] <= R) || (L <= r[i] && r[i] <= R)   题目理解错了
        
    
*/