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
    1.����ͼ�ͺܼ���
        ������
        ��С�������
        preL preR  ��nL nR���Ƚ�
            preR <nL
                ;
            preR >=nL
                preR ��nR��  ȥ�ϴ�ֵ
*/