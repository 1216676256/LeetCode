class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int ans = 0;
        int lenA = A.length;
        int lenB = B.length;
        int lenC = C.length;
        int lenD = D.length;
        if (lenA == 0 || lenB == 0 || lenC == 0 || lenD == 0)
            return ans;
        Arrays.sort(A);
        Arrays.sort(B);
        Arrays.sort(C);
        Arrays.sort(D);
        if (A[0] + B[0] + C[0] + D[0] > 0)
            return 0;

        for (int i = 0; i < lenA; ++i) {
            if(A[i] + B[0] + C[0] + D[0] > 0)
                break;
            for (int j = 0; j < lenB; ++j) {
                int L = 0;
                int R = lenD - 1;
                if(A[i] + B[j] + C[0] + D[0] > 0)
                    continue;
                while (L < lenC && R >= 0) {
                    //System.out.println("AAAA" + L +"  "+ R);
                    int tmp = A[i] + B[j] + C[L] + D[R];
                    if (tmp == 0) {
                        int cnt1 = 1;
                        int cnt2 = 1;
                        while (L + 1 < lenC && C[L] == C[L + 1]) {
                            cnt1++;
                            L++;
                        }
                        while (R > 0 && D[R] == D[R - 1]) {
                            R--;
                            cnt2++;
                        }
                        ans += cnt1 * cnt2;
                        L++;
                        R--;
                    } else if (tmp > 0) {
                        R--;
                    } else if (tmp < 0) {
                        L++;
                    }
                }
            }
        }
        return ans;
    }
}
/**
 * 1. 就是18题 四数之和的变形
 * 题目只是求元组的个数，并不是求元组列表，因此可以排序
 * <p>
 * 超时了，但可以跑出来  (答案是对的)
 */