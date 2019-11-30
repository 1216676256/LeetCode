class Solution {
public:
    vector<int>sum;
    int res = 0;
    vector<vector<int>>edge;
    vector<int>cnt_node;  //ͳ��ÿ���ڵ��ж����ӽڵ�
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
                edge[parent[i]].push_back(i);  // ������   ���ڵ� ָ���ӽڵ�
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
            res += cnt_node[rt];  //�Լ�������ڵ�ҲҪ����ȥ
            return ;
        }
        for(int a : edge[rt]){
            dfs_cnt(a);
        }
        return ;
    }
    
};
/**
    ���͵�dfs��Ŀ   �ټ��ϼ�¼  �����ͣ�������
*/