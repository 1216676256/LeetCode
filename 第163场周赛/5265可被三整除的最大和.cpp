class Solution {
public:
    static bool cmp(int a,int b){
        return a<b;
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<int>tmp1;
        vector<int>tmp2;
        int sum  = 0;
        for(int a: nums){
            sum+=a;
            if(a%3 == 1){
                tmp1.push_back(a);
            }
            else if(a%3==2){
                tmp2.push_back(a);
            }
        }
        sort(tmp1.begin(),tmp1.end(),cmp);
        sort(tmp2.begin(),tmp2.end(),cmp);
        int ans = 0x7FFFFFFF;
        //cout<<sum<<endl;
        if(sum%3 == 0){
            ans = 0;
        }
        else if(sum%3 == 1){
            /*   2 2
                 1
            */
            if(tmp2.size() >=2)
                ans = min(ans, tmp2[0] + tmp2[1]);
            if(tmp1.size()>=1)
                ans = min(ans,tmp1[0]);
        }
        else if(sum%3 == 2){
            if(tmp1.size()>=2){
                ans = min(ans,tmp1[0] + tmp1[1]);
            }
            if(tmp2.size()>=1){
                ans = min(ans, tmp2[0]);
                //cout<<tmp2[0]<<"AAA"<<endl;
            }
        }
        return sum - ans;
    }
};

/**
  ��ͳ���ܺ� sum
    1.  sum��3����  ���Ǵ���
    �������Ϊ��3ģ  ��1 ->tmp1,   ��2->tmp2;
        2.  sum%3 == 1
            ��tmp1����С��   tmp2 ��С���������   ���
        3.   ==2
            ͬ2
*/