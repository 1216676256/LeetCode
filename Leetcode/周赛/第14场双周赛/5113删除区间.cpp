class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int L = toBeRemoved[0];
        int R = toBeRemoved[1];
        vector<vector<int>>ans;
        for(vector<int> a : intervals){
            if(L <= a[0] && a[1] <= R)   //���˶�������
                continue;
            else if((L <=  a[0] && a[0] <= R) || (L <= a[1] && a[1] <= R)){  //ֻ��һ��������{
                if(a[0] < L){
                    ans.push_back({a[0], L});
                }
                else if(a[1] > R){
                    ans.push_back({R, a[1]});
                }
            }
            else  if(L >= a[0] && R <= a[1]){
                //toBe������������
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
  1. �ͺϲ��������   ��һ��ͼ��������
        (L <=  l[i] && l[i] <= R) || (L <= r[i] && r[i] <= R)   ��Ŀ������
        
    
*/