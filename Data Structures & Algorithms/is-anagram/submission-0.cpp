class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char,int> s_freq, t_freq;

        if(s.length()!=t.length()){
           return false;
        }
        else{
            for (int i = 0; i < s.length(); i++) {
                s_freq[s[i]]=s_freq[s[i]]+1;
                t_freq[t[i]]=t_freq[t[i]]+1;
            }
            for (int i = 0; i < s.length(); i++) {
                if(s_freq[s[i]] != t_freq[s[i]]){
                    return false;
                }              
                
            }
            return true;

        }
    }
};
