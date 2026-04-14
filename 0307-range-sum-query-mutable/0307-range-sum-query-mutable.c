/*
Segment Tree Implementation
*/

typedef struct {
    int* tree;
    int n;
} NumArray;

void buildTree(NumArray* obj, int* nums, int node, int start, int end) {
    if (start == end) {
        obj->tree[node] = nums[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(obj, nums, 2*node+1, start, mid);
    buildTree(obj, nums, 2*node+2, mid+1, end);

    obj->tree[node] = obj->tree[2*node+1] + obj->tree[2*node+2];
}

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->n = numsSize;
    obj->tree = (int*)calloc(4 * numsSize, sizeof(int));

    buildTree(obj, nums, 0, 0, numsSize - 1);
    return obj;
}

void updateTree(NumArray* obj, int node, int start, int end, int index, int val) {
    if (start == end) {
        obj->tree[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    if (index <= mid)
        updateTree(obj, 2*node+1, start, mid, index, val);
    else
        updateTree(obj, 2*node+2, mid+1, end, index, val);

    obj->tree[node] = obj->tree[2*node+1] + obj->tree[2*node+2];
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    updateTree(obj, 0, 0, obj->n - 1, index, val);
}

int sumRangeTree(NumArray* obj, int node, int start, int end, int left, int right) {
    if (right < start || left > end)
        return 0;

    if (left <= start && end <= right)
        return obj->tree[node];

    int mid = (start + end) / 2;
    return sumRangeTree(obj, 2*node+1, start, mid, left, right) +
           sumRangeTree(obj, 2*node+2, mid+1, end, left, right);
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return sumRangeTree(obj, 0, 0, obj->n - 1, left, right);
}

void numArrayFree(NumArray* obj) {
    free(obj->tree);
    free(obj);
}