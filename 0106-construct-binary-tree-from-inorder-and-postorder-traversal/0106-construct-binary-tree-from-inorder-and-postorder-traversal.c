/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* build(int* inorder, int inStart, int inEnd,
                       int* postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return NULL;

    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = postorder[postEnd];
    root->left = root->right = NULL;

    int idx = inStart;
    while (inorder[idx] != root->val) idx++;

    int leftSize = idx - inStart;

    root->left = build(inorder, inStart, idx - 1,
                       postorder, postStart, postStart + leftSize - 1);

    root->right = build(inorder, idx + 1, inEnd,
                        postorder, postStart + leftSize, postEnd - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    return build(inorder, 0, inorderSize - 1,
                 postorder, 0, postorderSize - 1);
}