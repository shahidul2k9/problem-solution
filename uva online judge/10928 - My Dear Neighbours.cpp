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



#define MAX_CREATERS 5000
struct Node{
    int outdegree;
    int id;
};
bool callback(Node x, Node y){
    if(x.outdegree != y.outdegree) return x.outdegree < y.outdegree;
    return x.id < y.id;
}
int main(){

    //freopen("input.txt", "r", stdin);
    Node nodelist[1002];
    int nodes,test;
    string line;
    stringstream ss;
    int x, ans;


    scanf("%d", &test);
    while(test--){
        scanf("%d", &nodes);getchar();
        for(int i = 1; i <= nodes; i++){

            nodelist[i].id = i;
            nodelist[i].outdegree = 0;

            getline(cin,line);
            ss.clear();
            ss << line;
            while(ss >> x)
                nodelist[i].outdegree += 1;
        }

        sort(nodelist+1, nodelist + nodes + 1, callback);
        ans = nodelist[1].outdegree;
        printf("%d", nodelist[1].id);

        for(int i = 2; i <=nodes;i++){
            if(ans == nodelist[i].outdegree)
                printf(" %d", nodelist[i].id);
            else break;
        }
        printf("\n");
    }


	return 0;
}
