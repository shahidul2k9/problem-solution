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
typedef pair < int , int > ii;



int main(){
    //freopen("input.txt", "r", stdin);
    vector < int > g[101];
    map < int, string > rm;
    map < string, int > m;
    int N, M;
    int deg[101];
    string name, from, to;
    int cs = 1;
    map< int, int > s;
    while(scanf("%d", &N) == 1){


        for( int i = 1; i <= N; i++ ){
            cin >> name;
            m[name] = i;
            rm[i] = name;
        }
        scanf("%d", &M);
        memset(deg, 0, sizeof(int)* (N+1));
        for( int i = 1; i <= M; i++ ){
            cin >> from >> to;
            g[m[from]].push_back(m[to]);
            deg[m[to]]++;
        }
        for( int i = 1; i <= N; i++ ){
            s[i] = deg[i];
        }
        printf("Case #%d: Dilbert should drink beverages in this order: ", cs++);

        map<int, int> :: iterator it;
        int x, next;
        for(int i = 1; i <= N; i++ ){
            int sz = s.size();

            it = s.begin();
            while(it != s.end() && (*it).second != 0)
                it++;

            x = (*it).first;
            cout << rm[x];
            if( i != N) cout << " ";

            for(int k = 0; k < (int)g[x].size(); k++){
                next = g[x][k];
                s[next]--;
            }
            s.erase(it);
        }
        printf(".\n\n");
        s.clear();
        m.clear();
        rm.clear();
        for(int i = 1; i <= N; i++ )g[i].clear();
    }




	return 0;
}
