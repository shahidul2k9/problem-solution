#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > ii;

#define MAX  5009

vector < int > g[MAX];
int T[MAX],  L[MAX];
bool color[MAX];
int M[MAX][13];
int N,E, Q;


void bfs(int from){
    int to;

    queue < int > q;
    q.push(from);
    color[from] = true;
    while(!q.empty()){
    from = q.front();q.pop();

    for(int i = 0; i < g[from].size(); i++){
        to = g[from][i];
            if(color[to] == false){
            T[to] = from;
            L[to]  = L[from] + 1;
            color[to] = true;
            q.push(to);
        }
    }
    }
}


 void process()  {
     memset(M, -1, sizeof M);
     for(int i = 1; i <= N; i++)
        M[i][0] = T[i];

    for(int j = 1; (1 << j) < N; j++)
        for(int i = 1; i <= N; i++)
            if(M[i][j-1] != -1)
                M[i][j] = M [M[i][j-1]]  [j-1];

  }

int LCA(int p, int q){

    if(L[p] < L[q]) swap(p, q);

    int lg = log2(L[p]);

    for(int i = lg; i >= 0; i--)
        if(L[p] - (1 << i) >= L[q])
            p = M[p][i];

    if( p == q ) return p;
    for(int i = lg; i >= 0; i--)
        if(M[p][i] != -1 && M[p][i] != M[q][i]){
            p = M[p][i];
            q = M[q][i];
        }
    return T[p];



}

int kthNode(int p, int level){

     int lg = log2(L[p]);
    for(int i = lg; i >= 0; i--)
        if(L[p] - (1 << i) >= level)
            p = M[p][i];

    return p;

    }
int main() {
   freopen("input.txt", "r", stdin);
    int st, en, lca, ans;

    while(scanf("%d", &N) && N){
        E = N - 1;
        for(int  i = 1; i <= E; i++){
                scanf("%d %d", &st, &en);

            g[st].push_back(en);
            g[en].push_back(st);

        }

        memset(T, -1, sizeof T);
        memset(color, false, sizeof color);
        L[1] = 0;
        memset(T, -1, sizeof T);

        bfs(1);




        process();


        scanf("%d", &Q);
        while(Q--){
            scanf("%d %d", &st, &en);


            lca = LCA(st, en);

            int dist = L[en] + L[st] - 2*L[lca];


            if(dist&1){
                if(L[st] > L[en])
                    ans = kthNode(st, L[st] -  dist/2 );

                else ans = kthNode(en, L[en] - dist/2 );

                if(ans < T[ans])
                printf("The fleas jump forever between %d and %d.\n", ans, T[ans]);
                else
                printf("The fleas jump forever between %d and %d.\n", T[ans], ans);
            }

            else{

                if(L[st] > L[en])
                    ans = kthNode(st, L[st] - dist/2);
                else {

                    ans = kthNode(en, L[en] - dist/2);
                    }
                printf("The fleas meet at %d.\n",ans);

            }
        }
    for(int i = 1; i <= N; i++)g[i].clear();
    }

	return 0;
}
/*
TLE
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > ii;

#define MAX  5005

vector < int > g[MAX];
int T[MAX], P[MAX], L[MAX];
bool color[MAX];
int N, nr, H, E, Q;

void bfs(int from){
    int to;

    queue < int > q;
    q.push(from);

    while(!q.empty()){
    from = q.front();q.pop();

    for(int i = 0; i < g[from].size(); i++){
        to = g[from][i];

            T[to] = from;
            L[to]  = L[from] + 1;
            H = max(H, L[to]);
            q.push(to);
    }

    }
}



void dfs(int from){
    int to;
    for(int i = 0; i < g[from].size(); i++){
        to = g[from][i];

            T[to] = from;
            L[to]  = L[from] + 1;
            H = max(H, L[to]);
            dfs(to);
    }
}



 void process(int node)  {
    int to;

  //if node is situated in the first
  //section then P[node] = 1
  //if node is situated at the beginning
  //of some section then P[node] = T[node]
  //if none of those two cases occurs, then
  //P[node] = P[T[node]]
      if (L[node] < nr)
          P[node] = 1;
      else
          if(!(L[node] % nr))
              P[node] = T[node];
          else
              P[node] = P[T[node]];

     for(int i = 0; i < g[node].size(); i++){
        to = g[node][i];
        if(color[to] == false){
        color[to] = true;
         process(to);
     }
     }
  }

 int LCA( int x, int y)
  {
  //as long as the node in the next section of
  //x and y is not one common ancestor
  //we get the node situated on the smaller
  //lever closer
      while (P[x] != P[y])
          if (L[x] > L[y])
             x = P[x];
          else
     	       y = P[y];

  //now they are in the same section, so we trivially compute the LCA
      while (x != y)
          if (L[x] > L[y])
             x = T[x];
          else
             y = T[y];
      return x;
  }


int kthNode(int node, int level){

    while(L[node] - nr >= level){
        node = P[node];
    }

    while(L[node] != level){
        node = T[node];
    }

    return node;
    }
int main() {
    cout << log2(10000) << endl;
    freopen("input.txt", "r", stdin);
    int st, en, test, lca, ans;

    while(scanf("%d", &N) && N){
        E = N - 1;
        for(int  i = 1; i <= E; i++){
                scanf("%d %d", &st, &en);
        if(st < en)
            g[st].push_back(en);
        else g[en].push_back(st);

        }
        memset(T, -1, sizeof T);

        L[1] = 0;
        T[1] = 1;
        H = 1;
        bfs(1);

        nr = ceil(sqrt(H));

        memset(color, false, sizeof color);
        color[1] = true;
        process(1);


        scanf("%d", &Q);
        while(Q--){
            scanf("%d %d", &st, &en);


                lca = LCA(st, en);
            int dist = L[en] + L[st] - 2*L[lca];


            if(dist&1){
                if(L[st] > L[en])
                    ans = kthNode(st, L[st] -  dist/2 );
                else ans = kthNode(en, L[en] - dist/2 );
                if(ans < T[ans])
                printf("The fleas jump forever between %d and %d.\n", ans, T[ans]);
                else
                printf("The fleas jump forever between %d and %d.\n", T[ans], ans);
            }

            else{

                if(L[st] > L[en])
                    ans = kthNode(st, L[st] - dist/2);
                else {

                    ans = kthNode(en, L[en] - dist/2);
                    }
                printf("The fleas meet at %d.\n",ans);

            }
        }
    for(int i = 1; i <= N; i++)g[i].clear();
    }

	return 0;
}
*/
/*
TLE
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > ii;

#define MAX  5000
#define WHITE 0
#define GRAY 1
#define MAX  5000

vector < int > g[MAX +1 ];
int E[2*MAX], H[MAX + 1], L[2*MAX];
int color[MAX+1];
int N, Q, t;

void dfs(int from, int depth){

    int to;
    for(int i = 0; i < g[from].size(); i++){
    to = g[from][i];
        if(color[to] == WHITE){
            color[to] = GRAY;

            t++;
            H[to] = t;
            E[t] = to;
            L[t] = depth + 1;
            dfs(to, depth +1 );
        }

            t++;
            E[t] = from;
            L[t] = depth;




    }

}

int main() {

    freopen("input.txt", "r", stdin);
    int st, en, test,  ind;

    while(scanf("%d", &N) && N){

        for(int  i = 1; i < N; i++){
                scanf("%d %d", &st, &en);
        if(st < en)
            g[st].push_back(en);
        else
            g[en].push_back(st);

        }

    {
    t = 1;
    E[1] = 1;
    H[1] = 1;
    L[1] = 0;
    memset(color, WHITE, sizeof color);
    }

    dfs(1, 0);


    scanf("%d", &Q);
    while(Q--){
        scanf("%d %d", &st, &en);
        int i = H[st];
        int j = H[en];
        if(i > j) swap(i, j);
        int dif = j - i;
        if(dif &1){
            int from = i + dif/2;
            if(E[from] < E[from+1])
                printf("The fleas jump forever between %d and %d.\n", E[from], E[from+1]);
            else
                printf("The fleas jump forever between %d and %d.\n", E[from + 1], E[from]);
        }
        else{
            printf("The fleas meet at %d.\n", E[i + dif/2]);
        }
    }
    for(int i = 1; i <= N; i++)g[i].clear();
    }

	return 0;
}
*/
