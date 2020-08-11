/* ************************************************************************
> File Name:        求二叉树的最大深度，最小深度，节点数量
> Author:           SunXiuyang
> leetcode刷题攻略: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/

// 二叉树的最大深度 递归

```
class Solution {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        return 1 + max(getDepth(node->left), getDepth(node->right));
    }
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};
```

// 二叉树的最大深度 迭代法

```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size(); // 必须要这么写，要固定size大小
            depth++;    // 记录深度
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return depth;
    }
};
```

// 二叉树的最小深度 递归
```
class Solution {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        // 当一个左子树为空，右不为空，这时并不是最低点
        if (node->left == NULL && node->right != NULL) {
            return 1 + getDepth(node->right);
        }
        // 当一个右子树为空，左不为空，这时并不是最低点
        if (node->left != NULL && node->right == NULL) {
            return 1 + getDepth(node->left);
        }
        return 1 + min(getDepth(node->left), getDepth(node->right));
    }

    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};
```
// 二叉树的最小深度 迭代法
//
```
class Solution {
public:

    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size(); // 必须要这么写，要固定size大小
            depth++;
            int flag = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (!node->left && !node->right) { // 当左右孩子都为空的时候，说明是最低点的一层了，退出
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
        }
        return depth;
    }
};
```

// 完全二叉树的节点数量 递归
```
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```

// 完全二叉树的节点数量 迭代-广度优先

// 二叉树层序遍历模板详解：https://github.com/youngyangyang04/leetcode/blob/master/problems/0102.二叉树的层序遍历.md

```
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        int count = 0;
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                result++;   // 记录遍历的层数
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};
```

