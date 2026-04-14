/*
Find left and right boundaries
Time: O(n)
*/

int findUnsortedSubarray(int* nums, int numsSize) {
    int left = -1, right = -1;
    int maxVal = nums[0], minVal = nums[numsSize - 1];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < maxVal)
            right = i;
        else
            maxVal = nums[i];
    }

    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] > minVal)
            left = i;
        else
            minVal = nums[i];
    }

    return (right == -1) ? 0 : right - left + 1;
}