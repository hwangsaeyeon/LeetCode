class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            // 왼쪽 구간이 정렬되어 있는 경우
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;  // target이 왼쪽에 있음
                else
                    left = mid + 1;   // target이 오른쪽에 있음
            }
            // 오른쪽 구간이 정렬되어 있는 경우
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;   // target이 오른쪽에 있음
                else
                    right = mid - 1;  // target이 왼쪽에 있음
            }
        }

        return -1;
    }
};
