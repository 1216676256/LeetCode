class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int len =colsum.size();
        vector<vector<int>>ans;
        vector<vector<int>>res;
        int sum = 0;
        int cnt = 0;
        for(auto a: colsum){
            if(a== 2)
                cnt++;
            sum+=a;
        }
        
        //cout<<sum<<endl;
        if(sum != (upper + lower))
            return res;
        upper-=cnt;
        lower-=cnt;
        if(upper<0||lower<0)
            return res;
        ans.resize(2, vector<int>(len, 0));//合格之后再初始化
        //要先统计一下2的个数
        for(int i = 0; i< len ;i++){
            if(colsum[i]==0 || colsum[i] == 2){
                ans[0][i]  = colsum[i]/2;
                ans[1][i] = colsum[i]/2;
                /*if(colsum[i] == 2){
                    upper--;
                    lower--;//为2上下个数都要减1
                }*/
            }
            else if(colsum[i] == 1){
                if(upper){
                    upper--;
                    ans[0][i] = 1;
                    ans[1][i] = 0;
                }
                else{
                    lower--;
                    ans[0][i] = 0;
                    ans[1][i] = 1;
                }
            }
        }
        return ans;
    } 
};