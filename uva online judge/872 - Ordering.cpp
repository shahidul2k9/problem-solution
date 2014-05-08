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
char seq[20];
int tup[20];
bool in[92];
bool cons[92][92];
int N;
bool ans;
bool isok(int d){
    for( int i = 0; i < d; i++ )
        if(cons [ seq[ tup[d] ] ] [ seq[ tup[i]] ])
            return false;
    return true;
}
void bkt(int depth){
    //printf("%d\n", depth);

    if(!isok(depth))return;
    if( depth == N-1){
        ans = true;
        for( int i = 0; i < N-1; i++ )printf("%c ",seq[tup[i]]);
        printf("%c\n", seq[tup[N-1]]);
        return;
    }
    for(int i = 0; i < N; i++ ){
        if(in[ seq[i] ] == false){
            in[seq[i]] = true;
            tup[depth+1] =i;
            bkt(depth+1 );
            in[ seq[i] ] = false;
        }
    }
}
int main(){
  // freopen("input.txt", "r", stdin);
    string line;
    stringstream ss;
    char a, b;
    int test;
    scanf("%d", &test);
    getline(cin, line);getline(cin, line);
    while(test--){
        ans = false;
        getline(cin, line);
        ss.clear();
        ss << line;
        N = -1;
        while(ss >> seq[++N]);
        memset(cons, false, sizeof(cons));
        getline(cin,line);
        for( int i = 0; i < (int)line.size(); i++ )
            if(line[i] == '<') line[i] = ' ';
        ss.clear();
        ss << line;
        while(ss >> a >> b)
            cons[a][b] = true;
        sort(seq, seq+N);
        memset(in, false, sizeof(in));

        for(int i = 0; i < N; i++ ){
            in[ seq[i] ] = true;
            tup[0] = i;
            bkt(0);
            in[ seq[i] ] = false;
        }
        if( !ans )puts("NO");
        if(test)puts("");
        getline(cin, line);

        }


	return 0;
}
