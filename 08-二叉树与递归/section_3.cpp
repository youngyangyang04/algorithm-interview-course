/* ************************************************************************
> File Name:        二叉树深度优先遍历：前中后序遍历（迭代法） 
> Author:           SunXiuyang
> leetcode刷题攻略: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/

// 前序遍历 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node != NULL) result.push_back(node->val);
            else continue;
            st.push(node->right);
            st.push(node->left);
        }
        return result;
    }
};


// 中序遍历 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};


// 后序遍历
class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node != NULL) result.push_back(node->val);
            else continue;
            st.push(node->left);
            st.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// 前中后通用写法 
// 0094.二叉树的中序遍历：https://github.com/youngyangyang04/leetcode/blob/master/problems/0094.二叉树的中序遍历.md
// 中序遍历 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right) st.push(node->right); // 添加右节点
                st.push(node); // 添加中节点
                st.push(NULL); // 中节点访问过，但是还没有处理，需要做一下标记。
                if (node->left) st.push(node->left); // 添加左节点
            } else {
                st.pop(); // 将空节点弹出
                node = st.top(); // 重新取出栈中元素
                st.pop();
                result.push_back(node->val); // 加入到数组中
            }
        }
        return result;
    }
};


// 前序遍历 
// 0144.二叉树的前序遍历：https://github.com/youngyangyang04/leetcode/blob/master/problems/0144.二叉树的前序遍历.md
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
                st.push(node);
                st.push(NULL);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};

// 后序遍历 
// 0145.二叉树的后序遍历：https://github.com/youngyangyang04/leetcode/blob/master/problems/0145.二叉树的后序遍历.md
class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node);
                st.push(NULL);
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);

            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};

