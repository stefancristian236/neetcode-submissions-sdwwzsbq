class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        
        map<char, int> m1;

        for (const auto i : s){
            m1[i]++;
        }

        for (const auto i : t){
            m1[i]--;
            if (m1[i] < 0){
                return false;
            }
        }
        return true;
    }
};
