class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> triplets;
        if (nums.size() < 3) return triplets;
        
        quicksort(nums, 0, nums.size() - 1);
        int target;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else if (sum == target) {
                    std::vector<int> aux;
                    triplets.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    right--;
                    left++;
                }
            }
        }

        return triplets;
    }

    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (size_t j = low; j <= high - 1; ++j) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quicksort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quicksort(arr, low, pi - 1);
            quicksort(arr, pi + 1, high);
        }
    }
};
