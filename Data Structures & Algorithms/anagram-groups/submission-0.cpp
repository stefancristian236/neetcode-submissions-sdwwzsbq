class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::string, std::vector<std::string>> myMap;
        for(int i = 0; i < strs.size(); ++i) {
            std::string key = strs[i];
            std::sort(key.begin(), key.end());
            myMap[key].push_back(strs[i]);        
        }


        std::vector<std::vector<std::string>> arr;
        for (const auto group : myMap){
            arr.push_back(group.second);
        }
        return arr;
    }
};
