/* ************************************************************************
> File Name:        第八节面试题：二叉搜索树的遍历与验证
> Author:           SunXiuyang
> leetcode刷题攻略: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/

// 二叉搜索树中的搜索题解：https://github.com/youngyangyang04/leetcode/blob/master/problems/0700.二叉搜索树中的搜索.md
// 700.二叉搜索树中的搜索-递归
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) return root;
        if (root->val > val) return searchBST(root->left, val);
        if (root->val < val) return searchBST(root->right, val);
        return NULL;
    }
};

// 700.二叉搜索树中的搜索-迭代 
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL) {
            if (root->val > val) root = root->left;
            else if (root->val < val) root = root->right;
            else return root;
        }
        return NULL;
    }
};

// 0098.验证二叉搜索树题解：https://github.com/youngyangyang04/leetcode/blob/master/problems/0098.验证二叉搜索树.md
// 使用long long 最小值 
class Solution {
public:
    long long maxVal = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        bool left = isValidBST(root->left);
        // 中序遍历，验证遍历的元素是不是从小到大
        if (maxVal < root->val) maxVal = root->val;
        else return false;
        bool right = isValidBST(root->right);
        return left && right;
    }
};

// 不局限于最小值
class Solution {
public:
    long long maxVal = 0; // 记录中序遍历的过程中出现过的最大值
    bool flag = false; // 标记是否取到了最左面节点的数值
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        bool left = isValidBST(root->left);
        if (!flag) {
            maxVal = root->val;
            flag = true;
        } else {
            // 中序遍历，这里相当于从大到小进行比较
            if (maxVal < root->val) maxVal = root->val;
            else return false;
        }
        bool right = isValidBST(root->right);
        return left && right;
    }
};

