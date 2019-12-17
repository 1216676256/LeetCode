class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        map<string,string>mp;
        int len = regions.size();
        for(int i = 0; i< len; i++){
            int lens = regions[i].size();
            for(int j =0; j< lens; j++){
                string s1= regions[i][0];
                string s = regions[i][j];
                if(j == 0){
                    if(mp[s1] == ""){
                        mp[s1] = "";
                    }
                }
                else{
                    mp[s] = s1;
                }
            }
        }
        
        map<string,int>vis;
        string now = region1;
        while(now != ""){
            //cout<<now<<endl;
            vis[now]  = 1;
            now = mp[now];
        }
        now = region2;
        while(now != ""){
            if(vis[now] == 1)
                return now;
            now = mp[now];
        }
        return "North AmericaAAA";
    }
};

/** 
    看着有点类似  最近公共祖先
    自己暴力的解法
    
*/