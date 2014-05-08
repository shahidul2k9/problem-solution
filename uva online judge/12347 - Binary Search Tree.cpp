

#include <string.h>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>


using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF INT_MAX


#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<int> > vvc;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<string, string> mss;
typedef map<string, char> msc;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define SQR(x) ((x)*(x))
#define PI 2*acos(0)
#define EPS 1e-7
#define MAX 200


struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node* context;
void goDown(Node* cur, int val){
    if(cur->data <= val){
        if(cur->right == NULL){
            cur->right = new Node(val);
            context = cur->right;
        }
        else
            goDown(cur->right, val);
        }
        else goDown(cur->left, val);

}
void postTraverse(Node* cur){
    if(cur == NULL)return;
    postTraverse(cur->left);
    postTraverse(cur->right);
    printf("%d\n", cur->data);
}
int main(){

    //freopen("input.txt", "r", stdin);

    Node* root;

    int val;
    scanf("%d", &val);
    root = new Node(val);
    context = root;
    while(scanf("%d", &val) == 1){
        if(val < context->data){
            context->left = new Node(val);
            context = context->left;
        }
        else {
            goDown(root, val);
        }
    }

    postTraverse(root);

	return 0;
}
