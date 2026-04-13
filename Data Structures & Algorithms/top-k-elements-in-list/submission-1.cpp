class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freqMap;
        for(int i = 0; i < nums.size(); ++i) {
            freqMap[nums[i]] += 1;
        }

        std::vector<std::pair<int, int>> arr;

        for (auto it : freqMap){
            arr.push_back(it);
        }
        std::sort(arr.begin(), arr.end(), [](std::pair<int, int> a,
                                            std::pair<int, int> b) -> bool
                                            {return a.second < b.second;});
        
        std::vector<int> result;
        for (int i = arr.size() - 1; i >= 0; --i) {
            if (k != 0){
                result.push_back(arr[i].first);
            }
            if (k == 0) {
                break;
            }
            k--;
        }
        return result;
    }
};
