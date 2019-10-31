class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mp;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            mp[nums[i]]++;
        }
        for(int i = 0; i < len; i++){
            if(mp[nums[i]] == 1)
                return nums[i];
        }
        return -1;
    }
};
/**
    1.��1����� ͳ�ƴ���
    ��2��������жϴ���   O(N)
    
    2. λ����
    
*/