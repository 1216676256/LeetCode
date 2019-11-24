class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;
        vector<string>tmp;
        sort(products.begin(), products.end());
        int len;
        int len1 = searchWord.size();
        for(int i = 0; i < len1; i++){
            int cnt = 0;
            tmp.clear();
            len = products.size();
            int flag = 0;
            for(int j = 0; j < len; j++){
                if(i > products[j].size())
                    continue;
                if(products[j][i] == searchWord[i]){
                    cnt++;
                    tmp.push_back(products[j]);
                }
                if(cnt == 3 && !flag){
                    flag = 1;
                    ans.push_back(tmp);
                    //cout<<"AAA"<<endl;
                }
            }
            if(cnt < 3){
                //cout<<"BBB"<<endl;
                ans.push_back(tmp);
            }
            //cout<<i<<"   "<<tmp.size()<<endl;
            products = tmp;
        }
        return ans;
    }
};