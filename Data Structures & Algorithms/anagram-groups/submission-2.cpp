class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string &s : strs) {
            string key(26, 0);  // 26 length fixed string

            for (char c : s) {
                key[c - 'a']++;   // direct increment
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto &it : mp) {
            res.push_back(it.second);
        }

        return res;
    }
};