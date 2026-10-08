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
        int index=0;
        while(index < s.length()){

            int j=index; int count=0;
            while (s[j]!= '#') {
                j++;
                count++;
            }
            int size = stoi(s.substr(index, count));
            if (size==0) {
                decd.push_back("");
                index+=2;
            }
            else{
                int start=index+count+1;
                int end= index+size+count;
                decd.push_back(s.substr(start, size));
                index=end+1;
            }
        }
        return decd;

    }
};
