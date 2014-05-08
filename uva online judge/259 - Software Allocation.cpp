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
vector < int > g[37];
bitset < 37 > visited;
int match[10];

bool matching(int from){
    visited[from] = true;
    int to;
    for(int i = 0; i < (int)g[from].size(); i++ ){
        to = g[from][i];
        if(match[to] == -1 || (!visited[match[to]] && matching(match[to]))){
            match[to] = from;
            return true;
        }
    }
    return false;
}
int main(){
    //freopen("input.txt","r", stdin);
    int apps[37];
    string line;
    int scheduled, total, id;
    while(getline(cin, line)){
        total = 0;
        memset(apps,0,sizeof(apps));
        do{
            id = line[0]-55;
            apps[id] += line[1] - 48;
            for( int i = 3; line[i] != ';'; i++ )
                g[id].push_back(line[i]-48);
            getline(cin, line);
        }
        while(!line.empty());
        visited.reset();

        memset(match, -1, sizeof(match));
        bool possible = true;
        scheduled = 0;
        for( int i = 10; i < 37; i++ ){
            if( !possible)break;
            total += apps[i];
            for(int a = 1; a <= apps[i]; a++ ){
                visited.reset();
                if(matching(i)) scheduled++;
                else {
                    possible = false;
                    break;
                }
            }
        }

        if(total != scheduled)printf("!\n");
        else {
            for( int i = 0; i < 10; i++ )
                if(match[i] == -1)putchar('_');
                else putchar(match[i]+55);
            puts("");
        }
        for(int i = 0; i < 37; i++ )
            g[i].clear();
    }

	return 0;
}
