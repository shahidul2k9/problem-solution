#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
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

#define N 5005
vi g[N];
int dist[N];
string st[N];
 char temp[N];
int nodes,edges,id;
void bfs(int src){
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    int u,v;
    while(!q.empty()){
        u = q.front();
        q.pop();
        FOR(i,0,g[u].size()-1){
            v = g[u][i];
            if(dist[v]==INF){
                dist[v] = dist[u] +1;
                q.push(v);
            }
        }
    }
}
void removeSpace(string line){
            int in = 0;
            for(int t=0;line[t]!=':'&&t<line.size();t++)
                if(line[t]!=' ')temp[in++]=line[t];
            temp[in] ='\0';
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int hash[N];
    int test,q,li,fp,lp,com,no,cs=0;
    string line,name;
    msi m;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &li, &q);
        getline(cin,line);
         id = 1;

        FOR(i,0,li-1){
            getline(cin,line);

            removeSpace(line);
            line = string(temp);

            fp = no = com = 0;

            FOR(j,0,line.size()-1){
                if(line[j]==','||line.size()-1==j){
                    com++;
                    if(com==2||line.size()-1==j){
                        lp = j;
                        if(line.size()-1==j)
                            name = line.substr(fp,lp+1-fp);
                        else
                        name = line.substr(fp,lp-fp);
                        if(!m[name])m[name] = id++;
                        hash[no++] = m[name];
                        com=0;
                        fp = j+1;
                    }
                }
            }

        FOR(p,0,no-1)
            FOR(q,1,no-1){
                g[hash[p]].push_back(hash[q]);
                g[hash[q]].push_back(hash[p]);
            }
        }

       FOR(i,1,id)dist[i] = INF;

       if(m.find("Erdos,P.")!=m.end())
            bfs(m["Erdos,P."]);
        cout << "Scenario "<<++cs<<endl;
        FOR(i,0,q-1){
            getline(cin,line);
            removeSpace(line);
            name = string(temp);
            if(m.find(name)==m.end()){cout << line << " infinity"<<endl;continue;}
            if(dist[m[name]]==INF)cout << line << " infinity"<<endl;
            else cout << line << " " << dist[m[name]]<<endl;
        }

        m.clear();
        FOR(i,0,id)g[i].clear();
    }
	return 0;
}
