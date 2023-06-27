/*
Binary Tree Postorder Traversal - Easy

Q: Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL){
            return ans;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }

    // ITERATIVE SOLUTION - USING 2 STACKS
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL){
            return ans;
        }
        stack<TreeNode*> st1, st2;
        st1.push(root);
        TreeNode* node = NULL;
        while(!st1.empty()){
            node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left != NULL){
                st1.push(node->left);
            }
            if(node->right != NULL){
                st1.push(node->right);
            }
        }

        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }

    // ITERATIVE SOLUTION - USING 1 STACK
};