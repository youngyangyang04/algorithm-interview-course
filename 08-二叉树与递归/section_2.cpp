/* ************************************************************************
> File Name:        二叉树深度优先遍历：前中后序遍历（递归法） 
> Author:           SunXiuyang
> leetcode刷题攻略: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/

// 递归中序遍历
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 0094.二叉树的中序遍历：https://github.com/youngyangyang04/leetcode/blob/master/problems/0094.二叉树的中序遍历.md

// 递归前序遍历
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 0144.二叉树的前序遍历：https://github.com/youngyangyang04/leetcode/blob/master/problems/0144.二叉树的前序遍历.md

// 递归后序遍历
class Solution {
public:
    void traversal(TreeNode* root, vector<int>& vec) {
        if (root == NULL) return;
        traversal(root->left, vec);
        traversal(root->right, vec);
        vec.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;

    }
};

// 0145.二叉树的后序遍历：https://github.com/youngyangyang04/leetcode/blob/master/problems/0145.二叉树的后序遍历.md
