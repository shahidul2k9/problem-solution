
#include<vector>
#include<iostream>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> lst;
        traverse(root, lst);
        return lst;
    }
    void traverse(TreeNode *r , vector<int> &lst){
        if(r == NULL) return;
        traverse(r->left,lst);
        traverse(r->right,lst);
        lst.push_back(r->val);
    }
};