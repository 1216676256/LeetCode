class Solution {
public:
    int div[3] = {2, 3, 5};
    bool isUgly(int num) {
        if(num == 1)
            return true;
        if(num == 0)
            return false;
        for(int i = 0; i < 3; i++){
            if(num % div[i] == 0){
                return isUgly(num / div[i]);
            }
        }
        return false;
    }
};