class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> setlist(nums.begin(), nums.end());
        int max_streak = 0;

        for (auto it : setlist){
            if (setlist.find(it - 1) == setlist.end()) {
                int current = it;
                int current_streak = 1;
                while(setlist.find(current + 1) != setlist.end()) {
                    current += 1;
                    current_streak += 1;
                }

                max_streak = std::max(max_streak, current_streak);
            }
        }
        return max_streak;
    }
};