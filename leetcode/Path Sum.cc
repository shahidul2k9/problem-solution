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
    bool hasPathSum(TreeNode *root, int sum) {
        if( root == NULL) return false;
        return hasPath(root, 0, sum);

    }
    bool hasPath(TreeNode *r, int cs, int sum){
        if(r == NULL) return false;
        if(r->left == NULL&& r->right == NULL) return cs+(r->val) == sum;

        return hasPath(r->left, cs+(r->val), sum) || hasPath(r->right, cs+(r->val), sum);

    }
};
