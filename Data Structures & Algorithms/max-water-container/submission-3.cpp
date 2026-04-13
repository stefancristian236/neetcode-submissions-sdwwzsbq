class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int left = 0;
        int right = heights.size() - 1;
            while (left < right){
                int area = min(heights[right], heights[left]) * (right - left);            
                if (area > max) {
                    max = area;
                }
                if (heights[right] > heights[left]) left++;
                else right--;
            }
        return max;
    }
};
