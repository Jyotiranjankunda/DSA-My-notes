// Problem link : https://leetcode.com/problems/binary-tree-preorder-traversal/

/*
Binary Tree Preorder Traversal - Easy

Q: Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]
 
Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> ans;
    
    // RECURSIVE SOLUTION
    // Time: O(n), Space: O(n)

    vector<int> preorderTraversal_recursive(TreeNode* root) {
        if(root == NULL){
            return ans;
        }
        ans.push_back(root->val);
        preorderTraversal_recursive(root->left);
        preorderTraversal_recursive(root->right);
        return ans;
    }

    // ITERATIVE SOLUTION
    // Time: O(n), Space: O(n)

    vector<int> preorderTraversal_iterative(TreeNode* root){
        if(root == NULL){
            return ans;
        }
        stack<TreeNode*> st;
        st.push(root);

        TreeNode* node = NULL;
        while(!st.empty()){
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right != NULL){
                st.push(node->right);
            }
            if(node->left != NULL){
                st.push(node->left);
            }
        }
        return ans;
    }
};