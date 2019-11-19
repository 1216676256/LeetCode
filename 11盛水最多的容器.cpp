class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = - 1;
        int len = height.size();
        int L = 0;
        int R = len - 1;
        while(L < R){
            ans = max(ans, min(height[L], height[R]) * (R - L));
            if(height[L] < height[R]){
                L++;
            }
            else R--;
        }
        return ans;
    }
};
/**
    1. ����ö��
    int ans = -1;
        int len = height.size();
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j< len; j++){
                ans = max(ans, min(height[i],height[j]) * (j - i));
            }
        }
        return ans;
    
    2.  ������
        ˫ָ�뷨
        ������ָ���Ϊ������ ������   
         ÿ�θ��ݾ����ƶ�һ��
*/