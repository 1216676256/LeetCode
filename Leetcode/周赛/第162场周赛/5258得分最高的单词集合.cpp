class Solution {
public:
    vector<int>have;
    int len;
    int ans = 0;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        have.resize(26,0);
        for(auto a : letters){
            have[a - 'a']++;
        }
        len = words.size();
        dfs(words,0,0,score);
        return ans;
    }
    //w  已经获得的价值
    void dfs(vector<string>& words,int ind,int w,vector<int>& score){
        if(ind == len){
            ans = max(ans,w);
            return ;
        }
        //可以组成
        int value = 0;
        string str = words[ind];
        int lens = str.size();
        int flag = 1;
        vector<int>remain = have;
        for(int i = 0 ;i < lens; i++){
            value+= score[str[i] - 'a'];
            if(have[str[i] - 'a'] == 0){
                flag = 0;
            }
            else
                have[str[i] - 'a']--;
        }
        if(flag == 0){
            have= remain;
        }
        else{
            dfs(words,ind + 1, w+ value,score);
            for(int i = 0 ;i < lens; i++){
                    have[str[i] - 'a']++;
            }
        }
        dfs(words,ind+ 1,w,score);
    }
};
/**  
有点像背包问题  
    一个单词有一定的价值（可能为0，因为组不了）   
        也要消耗一定的资源（字母个数）
    求资源一定的情况下，所能获得的最大价值
    
    考虑到单词的长度有点小  2^14 = 4096
    在加上遍历长度    4096 * 15  不会超时 
        用dfs
*/