class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int len = intervals.size();
        if(len == 0)
            return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        int preL = intervals[0][0];
        int preR = intervals[0][1];
        int nL,nR;
        for(int i = 1; i < len; i++){
            nL = intervals[i][0];
            nR = intervals[i][1];
            if(preR < nL){
                ans.push_back({preL, preR});
                preL = nL;
                preR = nR;
            }
            else{
                preR = max(preR, nR);
            }
        }
        ans.push_back({preL, preR});
        return ans;
    }
};
/**
    1.画个图就很简单了
        先排序
        从小到大遍历
        preL preR  和nL nR做比较
            preR <nL
                ;
            preR >=nL
                preR 和nR比  去较大值
*/