/*
Greedy
Time: O(n)
*/
int jump(int* nums, int numsSize) {
    int jumps = 0, end = 0, farthest = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        if (i + nums[i] > farthest)
            farthest = i + nums[i];

        if (i == end) {
            jumps++;
            end = farthest;
        }
    }

    return jumps;
}