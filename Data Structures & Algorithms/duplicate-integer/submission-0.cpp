class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> m1;
        for (auto i : nums){
            m1[i] += 1;
        }
        for (auto i : m1){
            if (i.second > 1){
                return true;
            }
        }
        return false;
    }
};