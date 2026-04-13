class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int count_zero = 0;
        std::vector<int> arr;

        for (const auto num : nums) {
            if (num == 0){
                count_zero += 1;
                continue;
            }
            prod *= num;
        }
        for (const auto num : nums) {
            if (count_zero > 1) {
                arr.push_back(0);
            } else if (count_zero == 1) {
                if (num == 0) {
                    arr.push_back(prod);
                } else arr.push_back(0);
            } else {
                arr.push_back(prod / num);
            }
        }
        return arr;
    }
};
