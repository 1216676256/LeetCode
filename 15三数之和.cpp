class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        int len = nums.size();
        //cout<<len<<endl;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len; i++){
            int L = i + 1;
            int R = len - 1;
            while(L<R){
               
                if(nums[i] + nums[L] + nums[R] > 0){
                    R--;
                }
                else if(nums[i] + nums[L] + nums[R] < 0){
                    L++;
                }
                else{ 
                    //cout<<i<<"AAA"<<L<<" "<<R<<endl;
                    ans.insert({nums[i], nums[L], nums[R]});
                    if(nums[R] == nums[L])
                        break;
                    /*while(R >= 1 && nums[R] == nums[R - 1])
                        R--;
                    while(L< len -2 && nums[L] == nums[L + 1])
                        L++;
                        */
                    R--;
                    L++;
                }
            }
        }
        vector<vector<int>>res;
        for(vector<int>a : ans){
            res.push_back(a);
        }
        return res;
    }
};

/**

    1.  ������
        ö�������ص�   ����ö���(mapyҲ��)  O(n^2 * log(n))
    
    2.   ��������  ����  +  ˫ָ��
         ��Ҫȥ��
         -4  1 1 3 3
         ȫ��0   �ᳬʱ
*/