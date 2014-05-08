#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;
int val;
struct Node {
    int val;
    Node(int val){
        this->val = val;
        this->left =  NULL;
        this->right = NULL;
    }
    Node* left;
    Node* right;
};

void build(Node* root){
    scanf("%d", &val);
    if(val != -1){
        root->left = new Node(val);
        build(root->left);
    }
    scanf("%d", &val);
    if(val != -1){
        root->right = new Node(val);
        build(root->right);
    }
}
void fallingLeaves(Node* root, map < int , int > &l, int pos){
    if(root == NULL) return;
    l[pos] += root->val;
    fallingLeaves(root->left, l, pos-1);
    fallingLeaves(root->right, l, pos+1);
}
void freeMemory(Node* root){
    if(root == NULL)return;
    freeMemory(root->left);
    freeMemory(root->right);
    delete root;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    int cs = 0;
    Node* root;
    map < int, int > leaves;
    while(scanf("%d", &n) == 1 && n != -1){
        root = new Node(n);
        build(root);
        leaves.clear();
        fallingLeaves(root, leaves, 0);
        printf("Case %d:\n", ++cs);
        for(map < int, int > :: iterator it = leaves.begin(); it != leaves.end(); it++){
            if(it != leaves.begin())printf(" ");
            printf("%d", (*it).second);
        }
        printf("\n\n");
        freeMemory(root);
    }
    return 0;
}
