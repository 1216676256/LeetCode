class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int len = points.size();
        if(len == 1)
            return 0;
        vector<int>a = points[0];
        int ans = 0;
        for(int i = 1; i < len; i++){
            ans += max(abs(points[i][0] - a[0]), abs(points[i][1] - a[1]));
            a = points[i];
        }
        return ans;
    }
};

/**
  题意  按顺序   就很简单了

*/