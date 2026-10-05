class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {

            int count[26] = {0};
            for (char ch : strs[i]) {
                count[ch - 'a']++;
            }

            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i])+"#";
            }

            mp[key].push_back(strs[i]);
        }

        vector<vector<string>> gs;
        for(auto &it : mp){
            gs.push_back(it.second);
        }
        return gs;
    }
};
