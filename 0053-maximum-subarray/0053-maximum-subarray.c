/*
Kadane's Algorithm
Time: O(n)
*/
int maxSubArray(int* nums, int numsSize) {
    int maxSum = nums[0], currSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        currSum = (currSum + nums[i] > nums[i]) ? currSum + nums[i] : nums[i];
        maxSum = (maxSum > currSum) ? maxSum : currSum;
    }

    return maxSum;
}