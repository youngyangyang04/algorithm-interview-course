/* ************************************************************************
> File Name:        第九节面试题：在二叉搜索树中插入节点与删除节点
> Author:           SunXiuyang
> leetcode刷题攻略: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/


// 701.二叉搜索树中的插入操作题解：https://github.com/youngyangyang04/leetcode/blob/master/problems/0701.二叉搜索树中的插入操作.md
// 701. 二叉搜索树中的插入操作 - 递归
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};

// 701. 二叉搜索树中的插入操作 - 迭代 
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* cur = root;
        TreeNode* parent = root; // 这个很重要，需要记录上一个节点，否则无法赋值新节点
        while (cur != NULL) {
            parent = cur;
            if (cur->val > val) cur = cur->left;
            else cur = cur->right;
        }
        TreeNode* node = new TreeNode(val);
        if (val < parent->val) parent->left = node;// 此时是用parent节点的进行赋值
        else parent->right = node;
        return root;
    }
};

// 450.删除二叉搜索树中的节点题解：https://github.com/youngyangyang04/leetcode/blob/master/problems/0450.删除二叉搜索树中的节点.md
// 450. 删除二叉搜索树中的节点 
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        if (root->val == key) {
            // 第一种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
            // 第二种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
            if (root->left == NULL) return root->right; 
            // 第三种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
            else if (root->right == NULL) return root->left; 
            // 第四种情况：左右孩子节点都不为空，则将删除节点的左孩子放到删除节点的右孩子的最左面节点的左孩子的位置
            // 返回删除节点右孩子为新的根节点。
            else {  
                TreeNode* cur = root->right;
                while(cur->left != NULL) {
                    cur = cur->left;
                }
                cur->left = root->left;
                root = root->right;
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};

