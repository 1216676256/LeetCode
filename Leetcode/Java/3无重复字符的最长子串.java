class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = s.length();
        int res = 1;
        Map<Character, Integer> mp = new HashMap<>();
        for (int i = 0; i < len; ++i) {
            mp.clear();
            int cnt = 0;
            for (int j = i; j < len; ++j) {
                if (null == mp.get(s.charAt(j))) {
                    res = max(res, ++cnt);
                    mp.put(s.charAt(j), 1);
                } else {
                    break;
                }
            }
        }
        return res;
    }
}