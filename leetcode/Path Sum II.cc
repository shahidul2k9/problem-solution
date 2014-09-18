#include<vector>
#include<cstdio>
#include<iostream>
#include<math.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > paths;
        vector<int> p;
        if(root == NULL) return paths;

        genPath(root, 0, sum, p, paths);
        return paths;

    }
    void genPath(TreeNode* r, int cs, int ts, vector<int> &p, vector< vector<int> > &paths){
        if(r == NULL )return;
        p.push_back(r->val);

        if(r->left == NULL && r->right == NULL && cs+(r->val) == ts)
                paths.push_back(p);

        genPath(r->left, cs+(r->val), ts, p, paths);
        genPath(r->right, cs+(r->val), ts,p,  paths);
            p.pop_back();
    }

};
