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

        TreeLinkNode *parents = nullptr, *children = root;
        root->next = nullptr;
        while (children != nullptr) {
            parent = children;
            children = nullptr;
            TreeLinkNode *lastOfChildren = nullptr;

            for (TreeLinkNode *p = parent; p != nullptr; p = p->next) {
                TreeLinkNode *leftChild = p->left, *rightChild = p->right;
                if (children == nullptr) {
                    if (leftChild == nullptr) {
                        children = rightChild;
                        lastOfChildren = rightChild;
                    } else {
                        children = leftChild;
                        if (rightChild == nullptr) {
                            lastOfChildren = leftChild;
                        } else {
                            leftChild->next = rightChild;
                            lastOfChildren = rightChild;
                        }
                    }
                } else {
                    if (leftChild == nullptr) {
                        if (rightChild != nullptr) {
                            lastOfChildren->next = rightChild;
                            lastOfChildren = rightChild;
                        }
                    } else {
                        lastOfChildren->next = leftChild;
                        if (rightChild == nullptr) {
                            lastOfChildren = leftChild;
                        } else {
                            leftChild->next = rightChild;
                            lastOfChildren = rightChild;
                        }
                    }
                } 
            }
        }
    }
};
