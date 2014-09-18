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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> lis;
        traverse(root, lis);
        return lis;
    }
    void traverse(TreeNode *r , vector<int> &lis){
        if(r == NULL)return;
        traverse(r->left, lis);
        lis.push_back(r->val);
        traverse(r->right,lis);
    }
};
