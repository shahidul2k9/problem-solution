#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
using namespace std;
#define ifor( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define dfor( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

#define SQR(x) ((x)*(x))
#define INF INT_MAX
#define EPS 1e-9
#define PI (2*acos(0.0))
#define SZ size()

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long ll;
typedef unsigned long long int ull;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<string, char> msc;
typedef vector<vector<ii>  > vvii;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODE 10009

bool comp(int a, int b){return a>b;}
int main()
{
   READ("input.txt");
    //WRITE("output.txt");
    int nodes, co, maxDeg;
    int deg[MAX_NODE];
    bool possible;
    while(scanf("%d", &nodes)==1&& nodes!=0){
        co = maxDeg = 0;
        possible = false;
        ifor(i,0,nodes-1){
            scanf("%d", &deg[i]);
            maxDeg = max(maxDeg,deg[i]);
            if(deg[i]%2!=0)co++;
        }

        if(maxDeg>=nodes||co%2!=0){
            printf("Not possible\n");
            continue;
        }



            ifor(i,0,nodes-1){
                 sort(deg, deg+nodes,comp);
                if(deg[nodes-1]<0)break; // if contains negative value then not possible
                else if(deg[i]==0&&deg[nodes-1]==0){ //if all contains zeros then possible
                    possible = true;
                    break;
                }
                int last = min(nodes-1,i+deg[i]);
                for(int j=i+1;j<=last;j++)deg[j] -=1; //delete first element and subtruct 1 from all others

            }


        if(possible)printf("Possible\n");
        else
        printf("Not possible\n");

    }
    return 0;
}
