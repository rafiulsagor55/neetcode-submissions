class Solution {
public:

    string encode(vector<string>& strs) {

        string result;

        for (string &s : strs) {
            result += to_string(s.size()) + "#" + s;
        }

        return result;
    }

    vector<string> decode(string s) {

        vector<string> decd;

        int index = 0;

        while (index < s.length()) {

            // find # 
            int j = index;

            while (s[j] != '#') {
                j++;
            }

            // length= j- index
            int size = stoi(s.substr(index, j - index));

            // # starting point of actual string
            j++;

            decd.push_back(s.substr(j, size));

            // next encoded string
            index = j + size;
        }

        return decd;
    }
};