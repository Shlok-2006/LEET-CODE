/*
Greedy: sort by second element
Time: O(n log n)
*/

int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[1] - y[1];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize) {
    qsort(pairs, pairsSize, sizeof(int*), cmp);

    int count = 0;
    int currEnd = -1001;

    for (int i = 0; i < pairsSize; i++) {
        if (pairs[i][0] > currEnd) {
            count++;
            currEnd = pairs[i][1];
        }
    }

    return count;
}