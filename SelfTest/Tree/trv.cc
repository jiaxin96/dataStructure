/**
 * File: e:\code\code\dataStructure\SelfTest\Tree\trv.cc
 * Project: e:\code\code\dataStructure
 * Created Date: Friday, September 1st 2017, 1:19:51 am
 * Author: JX
 * -----
 * Last Modified: Fri Sep 01 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* p = root;
        while (p || !s.empty()) {
            while (p != NULL) {
                ans.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            if (!s.empty()) {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return ans;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* p = root;
        while (p || !s.empty()) {
            while (p != NULL) {
                s.push(p);
                p = p->left;
            }
            if (!s.empty()) {
                p = s.top();
                s.pop();
                ans.push_back(p->val);
                p = p->right;
            }
        }
        return ans;
    }

    vector<int> posorderTraversal(TreeNode* root) {
        struct TempTreeNode {
            TreeNode* tn;
            bool isFirst;
            TempTreeNode(TreeNode* n, bool isF):TreeNode(n), isFirst(isF = false) {}
        };
        stack<TempTreeNode*> s;
        vector<int> ans;
        root* p = root;
        while (p || !s.empty()) {
            while (p != NULL) {
                TempTreeNode * tp = new TempTreeNode(p);
                s.push(tp);
                p = p->left;
            }
            if (!s.empty()) {
                TempTreeNode * tp = s.top();
                s.pop();
                if (tp->isFirst) {
                    tp->isFirst = false;
                    s.push(tp);
                    p = tp->tn->right;
                } else {
                    ans.push_back(tp->tn->val);
                    p = NULL;
                }
            }
        }
        return ans;
    }
};