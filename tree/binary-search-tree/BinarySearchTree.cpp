#include <cstdio>
#include <cstdlib>

using namespace std;

struct BinarySearchTreeNode {
    int data;
    BinarySearchTreeNode *left_child;
    BinarySearchTreeNode *right_child;
};

BinarySearchTreeNode *Find(BinarySearchTreeNode *root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        return Find(root->left_child, data);
    } else if (data > root->data) {
        return Find(root->right_child, data);
    }

    return root;
}

BinarySearchTreeNode *NonRecursiveFind(BinarySearchTreeNode *root, int data) {
    if (root == NULL) {
        return NULL;
    }

    while(root) {
        if (data < root->data) {
            root = root->left_child;
        } else if (data > root->data) {
            root = root->right_child;
        } else {
            return root;
        }
    }

    return NULL;
}

BinarySearchTreeNode *FindMinimum(BinarySearchTreeNode *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left_child == NULL) {
        return root;
    } else {
        return FindMinimum(root->left_child);
    }
}

BinarySearchTreeNode *NonRecursiveFindMinimum(BinarySearchTreeNode *root) {
    if (root == NULL) {
        return NULL;
    }

    while(root->left_child) {
        root = root->left_child;
    }

    return root;
}

BinarySearchTreeNode *FindMaximum(BinarySearchTreeNode *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right_child == NULL) {
        return root;
    } else {
        return FindMaximum(root->right_child);
    }
}

BinarySearchTreeNode *NonRecursiveFindMaximum(BinarySearchTreeNode *root) {
    if (root == NULL) {
        return NULL;
    }

    while(root->right_child) {
        root = root->right_child;
    }

    return root;
}

BinarySearchTreeNode *Insert(BinarySearchTreeNode *&root, int data) {
    if (root == NULL) {
        root = (BinarySearchTreeNode*) malloc(sizeof(BinarySearchTreeNode));
        root->data = data;
        root->left_child = root->right_child = NULL;
    } else {
        if (data < root->data) {
            root->left_child = Insert(root->left_child, data);
        } else if (data > root->data) {
            root->right_child = Insert(root->right_child, data);
        }
    }

    return root;
}

BinarySearchTreeNode *Delete(BinarySearchTreeNode *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left_child = Delete(root->left_child, data);
    } else if (data > root->data) {
        root->right_child = Delete(root->right_child, data);
    } else {
        if (root->left_child && root->right_child) {
            BinarySearchTreeNode *maximum = FindMaximum(root->left_child);

            root->data = maximum->data;
            root->left_child = Delete(root->left_child, root->data);
        } else {
            BinarySearchTreeNode *copy = root;
            
            if (root->left_child == NULL) {
                root = root->right_child;
            } else if (root->right_child == NULL) {
                root = root->left_child;
            }

            free(copy);
        }
    }

    return root;
}

BinarySearchTreeNode *FindLowestCommonAncestor(BinarySearchTreeNode *root, BinarySearchTreeNode *a, BinarySearchTreeNode *b) {
    while (true) {
        if (a->data < root->data && root->data < b->data) {
            return root;
        }

        if (b->data < root->data && root->data < a->data) {
            return root;
        }

        if (a->data < root->data) {
            root = root->left_child;
        } else {
            root = root->right_child;
        }
    }
}
