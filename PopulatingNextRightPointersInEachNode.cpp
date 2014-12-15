/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr)
            return;

        assign(root, nullptr);
    }

    void assign(TreeLinkNode *child, TreeLinkNode *sibling) {
        // In this question we assume a perfect binary tree
        if (child == nullptr)
            return;

        child->next = sibling;
        
        assign(child->left, child->right);
        assign(child->right, sibling != nullptr ? sibling->left : nullptr);
    }
};
