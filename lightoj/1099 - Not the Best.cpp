#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int > ii;
struct Graph{
     int mNodes, mEdges;
    static const int MAX_NODES = 5000+10;
    static const int INF = 1 << 28;
    vector<ii> g[MAX_NODES];
    void clear(){
        for(int i = 0; i <= mNodes; i++)
            g[i].clear();
    }
    void addEdge(int x, int y, int w){
        g[x].push_back(ii(y,w));
        g[y].push_back(ii(x,w));
    }
 
};
struct Node{
    int d, who, v;
    Node(){}
    Node(int label, int dist, int fs):v(label),d(dist),who(fs){}
    bool operator <(const Node &node) const{
        if(who != node.who)
            return who > node.who;
        if(d != node.d)
            return d > node.d;
        return v > node.v;
 
    }
};
int bfs(int src, int destination , const Graph &graph){
    vector<int> fbsp = vector<int>(graph.mNodes + 1, graph.INF);
    vector<int> sbsp = vector<int>(graph.mNodes + 1, graph.INF);
    fbsp[src]  = 0;
    priority_queue<Node> q;
    int from, who, w, to;
    Node top;
    q.push(Node(1,0,1));
    while( !q.empty()){
        top = q.top();q.pop();
        from = top.v;
        who = top.who;
 
        if(who == 1 && fbsp[from] == top.d)
            for(int i = 0; i < graph.g[from].size(); i++){
                to = graph.g[from][i].first;
                w = graph.g[from][i].second;
                if(fbsp[to] > fbsp[from] + w){
 
                        sbsp[to] = fbsp[to];
                        q.push(Node(to,sbsp[to], 2));
 
                    fbsp[to] = fbsp[from] + w;
                    q.push(Node(to, fbsp[to], 1));
                }
                if(fbsp[from] + w > fbsp[to] && fbsp[from] + w < sbsp[to]){
                    sbsp[to] = fbsp[from] + w;
                    q.push(Node(to, sbsp[to], 2));
                }
            }
        else if(sbsp[from] == top.d)
                for(int i = 0; i < graph.g[from].size(); i++){
                to = graph.g[from][i].first;
                w = graph.g[from][i].second;
                if(sbsp[to] > sbsp[from] + w){
                    sbsp[to] = sbsp[from] + w;
                    q.push(Node(to, sbsp[to], 2));
                }
            }
 
 
 
 
    }
    return sbsp[destination];
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
 
    Graph graph;
    int test, u, v, w, tc=1;
    scanf("%d", &test);
    while(test--){
    scanf("%d %d", &graph.mNodes, &graph.mEdges);
    graph.clear();
    for(int i = 0; i < graph.mEdges; i++){
        scanf("%d %d %d", &u, &v, &w);
        graph.addEdge(u,v,w);
 
    }
    printf("Case %d: %d\n",tc++, bfs(1,graph.mNodes, graph));
    }
 
    return 0;
}