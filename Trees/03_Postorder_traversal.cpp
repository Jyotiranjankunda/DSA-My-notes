// Problem link : https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    // Time: O(n), Space: O(n)

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
    // Time: O(n), Space: O(2n)

    vector<int> postorderTraversal_2Stack(TreeNode* root) {
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
    // Time: O(n), Space: O(n)

    vector<int> postorderTraversal_1Stack(TreeNode* root){
        vector<int> post;

        if(root == NULL){
            return post;
        }

        stack<TreeNode*> st;
        TreeNode* node = NULL;
        node = root;

        while(!st.empty() || node != NULL){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                TreeNode* temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->val);

                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        post.push_back(temp->val);
                    }
                }
                else{
                    node = temp;
                }
            }
        }

        return post;
    }
};