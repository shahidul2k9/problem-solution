#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
#include <climits>
using namespace std;
#define pb(x) push_back(x)
#define MAXNODE 500
#define INF INT_MAX
#define ff first
#define ss second
#define sz size()
typedef pair< int, int > pii;
typedef queue <int> qi;
vector< pii > g[MAXNODE];
int d[MAXNODE];
int bfs(int n, int src){
    int i,u,v;
    qi q;
    //memset(&d[0],INF,n);
    for(i=0;i<n;i++)d[i]=INF;
    q.push(src);
    d[src]=0;
 
    while(!q.empty()){
        u = q.front();q.pop();
        for(i=0;i<g[u].sz;i++)
            {
                v = g[u][i].first;
                if(d[v]>max(d[u],g[u][i].ss)){
                    d[v]=max(d[u],g[u][i].ss);
                    q.push(v);
                }
            }
    }
    for(i=0;i<n;i++){
        if(d[i]==INF)
            printf("Impossible\n");
       else printf("%d\n",d[i]);
    }
    return 0;
}
int main () {
       // freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        int n, e, i, j, u, v, w,test,cs=0;
        bool m[MAXNODE][MAXNODE];
        scanf("%d",&test);
        for(cs=1;cs<=test;cs++){
        scanf("%d %d",&n,&e);
        //memset(m,0,sizeof(m));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                m[i][j]=false;
        for(i = 0; i < n; i++) g[i].clear(); // forget previous info
        for(i = 0; i < e; i++) {
            scanf("%d %d %d",&u,&v,&w);
            if(m[u][v]){
                for(j=0;g[u][j].ff!=v;j++);
                    if(g[u][j].ss>w)
                    g[u][j].ss=w;
            }
            else{
                g[u].pb(pii(v, w));
                m[u][v]=true;
            }
            if(m[v][u]){
                for(j=0;g[v][j].ff!=u;j++);
                    if(g[v][j].ss>w)
                    g[v][j].ss=w;
            }
            else{
                g[v].pb(pii(u, w));
                m[v][u]=true;
            }
        }
        int t;
        scanf("%d",&t);
        printf("Case %d:\n",cs);
        bfs(n,t);
        }
 
    return 0;
}