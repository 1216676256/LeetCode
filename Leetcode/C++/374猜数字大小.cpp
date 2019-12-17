// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int cnt = 0;
        int L = 1;
        int R = n;
        while(L <= R){
            cnt++;
            int mid = L + (R - L)/2;
            if(guess(mid) == 0)
                return mid;
            else if(guess(mid) > 0){
                L = mid + 1;
            }
            else R = mid - 1;
        }
        return -1;
    }
};
/**
   1 2 3 4 5 6 7 8 9 10
   
   1 10    5
   5 10    7
   5 7     6
*/