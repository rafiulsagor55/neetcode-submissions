class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> flag;
        int i = 0, j = 0, maxi = 0, count = 0;
        int n = s.length();

        while (j < n) {
            if (flag[s[j]] == 0) {
                count++;
                flag[s[j]] = 1;
                j++;
                maxi = max(maxi, count);
            } else {
                count--;
                flag[s[i]] = 0;
                i++;
            }
        }

        return maxi;
    }
};