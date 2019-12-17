class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int len = intervals.size();
        if(len == 0){
            ans.push_back(newInterval);
            return ans;
        }
        if(newInterval.size() == 0)
            return intervals;
        int ind = binarySearch(intervals, newInterval);
        //cout<<ind<<endl;
        if(ind == len){
            intervals.push_back(newInterval);
            return intervals;
        }
        else{
            //int preL = intervals[ind][0];
           // int preR = intervals[ind][1];
            int preL = newInterval[0];
            int preR = newInterval[1];
            int flag = 1;
            for(int i = 0; i < len; i++){
                if(i < ind){
                    ans.push_back(intervals[i]);
                    continue;
                }
               /* else if(i == ind){
                    //  1 5
                    //  0 0
                    if()
                    preL = min(preL, newInterval[0]);
                    preR = max(preR, newInterval[1]);
                }*/
                else{
                    if(!flag){
                        ans.push_back(intervals[i]);
                    }
                    else{
                        if(preR < intervals[i][0]){
                            flag = 0;
                            ans.push_back({preL, preR});
                            ans.push_back(intervals[i]);
                        }
                        else{
                            preL = min(preL, intervals[i][0]);
                            preR = max(preR, intervals[i][1]);
                        }
                    }
                }
            }
            //  ����һֱ�ڸ���  �ͽ���ѭ��Ҫ����
            if(flag)
                ans.push_back({preL, preR});
        }
        return ans;
    }
    
    
    int  binarySearch(vector<vector<int>>& vec, vector<int>& n){
        int target = n[0];
        int L = 0;
        int R= vec.size() - 1;
        int ind = vec.size();
        while(L <= R){
            int mid = (L + R) >> 1;
            if(vec[mid][1] < target){
                L = mid + 1;
            }
            else if(vec[mid][1] >= target){
                R = mid - 1;
                ind = min(ind, mid);
            }
        }
        return ind;
    }
};

/**
    1.  1 3
        6 9
        ������  2   5
        1.1
            ԭ���������   ��˵�����
                        �Ҷ˵�Ҳ����
        1.2
            ���½ڵ����˵�  ��ԭ��������Ҷ˵㣨��  �Ƚϣ����֣�   logN
            �ҵ�ԭ�������  �������� �����ĵ�һ���ϵ���±�ind
        1.3 ������±꿪ʼ����  
            ����ص���һ��
        
*/

/*����
    [[1,5]]
    [0,0]
*/