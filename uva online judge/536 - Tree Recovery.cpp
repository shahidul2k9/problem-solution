#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
#define MAX_CHARS 27
char preo[MAX_CHARS], ino[MAX_CHARS];

struct Node{
    char key;
    Node *left;
    Node *right;
    Node(){
        this->key = key;
        left = NULL;
        right = NULL;
    }

};
int find(char ch, int lo, int hi, char * s){
    for(int i = lo; i <= hi; i++)
        if(s[i] == ch) return i;
}
void build(Node* root, int prelo, int prehi, int inlo, int inhi){
    char key = preo[prelo];
    int rpos = find(key, inlo, inhi, ino);
    root->key = key;

    int lsubs = rpos - inlo;;
    if(inlo < rpos){
            Node * lson = new Node;
            root->left = lson;
            build( lson, prelo+1, prelo+lsubs, inlo, rpos-1);

    }
    if(rpos < inhi){
        Node * rson = new Node;
        root->right = rson;
        build(rson, prelo+lsubs + 1, prehi, rpos+1, inhi);
    }
}

void postorder(Node * root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->key);

}

void clear(Node* root){
    if(root == NULL) return;
    clear(root->left);
    clear(root->right);
    delete root;
}
int main()
{

    //freopen("input.txt", "r", stdin);
    Node* root;
    while(scanf("%s %s", preo, ino) == 2){
        root = new Node;
        build(root, 0, strlen(preo)-1, 0, strlen(ino)-1);
        postorder(root);puts("");
        clear(root);
    }
    return 0;
}
