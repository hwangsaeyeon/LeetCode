class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;        // nums1의 마지막 유효 원소
        int j = n - 1;        // nums2의 마지막 원소
        int k = m + n - 1;    // nums1의 마지막 인덱스 (합쳐진 배열의 끝)

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // nums2에 남은 원소가 있다면 복사
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
