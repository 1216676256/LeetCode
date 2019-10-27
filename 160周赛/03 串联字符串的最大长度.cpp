class Solution {
public: 
    vector<int>val;
    int res = -1;
    int len;
    int maxLength(vector<string>& arr) {
        len = arr.size(); 
        val.resize(len, -1);
        for(int i = 0; i < len; i++){
            val[i] = judge(arr[i]);
           //cout<<val[i]<<endl;
        }
        dfs(arr, 0, 0, 0, "");
        return res;
    }
    int judge(string str){
        vector<bool>vis(26,false);
        int len = str.size();
        int val = 0;
        for(int i = 0; i < len; i++){
            if(vis[str[i] - 'a'])
                return -1;
            vis[str[i] - 'a'] = true;
            val += (1<<(str[i] - 'a'));
        }
        return val;
    }
    
    void dfs(vector<string>& arr, int ind, int sum,int length, string str){
        if(ind == len){
           // cout<<sum<<" "<<str<<endl;
            res = max(res, length);
            return ;
        }
        //cout<<sum<<"  AAA "<<ind<<endl;
        //cout<<(sum^val[ind])<<"  "<<sum + val[ind] <<"  "<< val[ind]<<endl;
        if(val[ind] == -1 || (sum ^ val[ind]) != (sum +val[ind])){
           // cout<<"BBB"<<endl;
             dfs(arr, ind + 1, sum, length, str);
        }
           
        else{
            //cout<<"CCC"<<endl;
            dfs(arr, ind + 1, sum + val[ind], length + arr[ind].length(), str + arr[ind]);
            dfs(arr, ind + 1, sum, length, str);
            
        }
    }
};