class Solution {
public:
    struct node{
        int x;
        int ind;
    };
    static bool cmp(node a, node b){
        return a.x < b.x;
    }

    vector<vector<int> >groupThePeople(vector<int>& groupSizes) {
        int len = groupSizes.size();
        vector<node>t;
        for(int i = 0; i < len; ++i){
            t.push_back({groupSizes[i], i});
        }
        sort(t.begin(), t.end(), cmp);
        vector<vector<int> >ans;
        vector<int>tmp;
        int val = 0;
        for(int i = 0; i < len; ++i){
            if(val == 0){
                if(tmp.size() != 0)
                    ans.push_back(tmp);
                tmp.clear();
                val = t[i].x;
            }
            tmp.push_back(t[i].ind);
            val--;
        }
        if(!tmp.empty()){
            ans.push_back(tmp);
        }
        return ans;
    }
};