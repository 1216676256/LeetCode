class Solution {
public:
    vector<int>sum;
    int res = 0;
    vector<vector<int>>edge;
    vector<int>cnt_node;  //统计每个节点有多少子节点
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        int root = -1;
        edge.resize(nodes);
        sum.resize(nodes, 0);
        cnt_node.resize(nodes, 0);
        for(int i = 0; i < nodes; ++i){
            if(parent[i] == -1){
                root = i;
            }
            else{
                edge[parent[i]].push_back(i);  // 方向存边   父节点 指向子节点
            }
        }
        dfs(root,value);
        dfs_cnt(root);
        /*for(int a : sum){
            cout<<a<<"  ";
        }
        cout<<endl;*/
        return nodes - res;
    }
    void dfs(int rt,vector<int>& value){
        int node_x = 1;
        int cnt = value[rt];
        for(int a : edge[rt]){
            dfs(a,value);
            cnt += sum[a];
            node_x += cnt_node[a];
        }
        sum[rt] = cnt;
        cnt_node[rt] = node_x;
        return ;
    }
    
    void dfs_cnt(int rt){
        if(sum[rt] == 0){
            res += cnt_node[rt];  //自己的这个节点也要算上去
            return ;
        }
        for(int a : edge[rt]){
            dfs_cnt(a);
        }
        return ;
    }
    
};
/**
    典型的dfs题目   再加上记录  子树和（含本身）
*/