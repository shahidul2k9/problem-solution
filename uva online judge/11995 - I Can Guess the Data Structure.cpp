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

int main()
{
   // READ("input.txt");
    //WRITE("output.txt");
    int value,op,com;
    while(scanf("%d", &op)==1){
    stack<int> st;
    queue<int> q;
    priority_queue<int> pq;
    bool isst,isq,ispq;
    isst = isq = ispq = true;
    ifor(i,1,op){
        scanf("%d %d",&com,&value);

        if(com==1){
            st.push(value);
            q.push(value);
            pq.push(value);
        }
        else{
            if(!st.empty()&&isst){
                if(st.top()!=value) isst = false;
                else st.pop();
            }
            else isst = false;

            if(!q.empty()&&isq){
                if(q.front()!=value) isq = false;
                else q.pop();
            }
            else isq = false;

            if(!pq.empty()&&ispq){
                if(pq.top()!=value) ispq = false;
                else pq.pop();
            }
            else ispq = false;
        }
    }
    if(isst&&!isq&&!ispq)printf("stack");
    else if(!isst&&isq&&!ispq)printf("queue");
    else if(!isst&&!isq&&ispq)printf("priority queue");
    else if(!isst&&!isq&&!ispq)printf("impossible");
    else printf("not sure");
    printf("\n");
    }

    return 0;
}
