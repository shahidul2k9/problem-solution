#include <stdio.h>
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
#include <string.h>
#include <sstream>
using namespace std;
#define LT 700
bool R[LT][LT];
int N, M, K, source, sink, id;
int match[LT];
bitset < LT > seen;
bool matching(int from ){

    for( int i = 1; i <= N; i++ ){

        if(R[from][i] && !seen.test(i)){
            seen.set(i);
            if(match[i] < 0 || matching(match[i])){
                match[i] = from;
                return true;
            }
        }

    }
    return false;
}
void floyd(){
    for( int k = 1; k <= id; k++ )
            for(int i = 1; i <= id; i++ )
                for(int j = 1; j <= id; j++ )
                    if(R[i][k]&& R[k][j])
                        R[i][j]  = true;
}

void print(){
    for(int i = 1; i <= N+M; i++ ){
        printf("%d =-> ",i );
        for(int j = 1; j <= N+M; j++ )
            printf("%d ", R[i][j]);
        puts("");
    }
}
int main(){
    //freopen("input.txt", "r", stdin);
    vector < int > lis;
    map < string, int > table;
    int test;
    string name, str;
    scanf("%d", &test);
    while(test--){
        table.clear();
        lis.clear();
        memset(R,false, sizeof(R));
        id = 0;
        scanf("%d", &N);
        for( int i = 1; i <= N; i++ ){
            cin >> name;
            table[name] = i;
        }
        id = N;
        scanf("%d", &M);
        for(int i = 1; i <= M; i++ ){
            cin >> name >> str;
            if( table[name] == 0)
                table[name] = ++id;
            lis.push_back(id);
            if( table[str] == 0)
                table[str] = ++id;

            R[table[name]][table[str]] =  true;
            //R[table[str]][table[name]]

        }
        scanf("%d", &K);
        for(int i = 1; i <= K; i++ ){
            cin >> name >> str;
            if(table[name] == 0) table[name] = ++id;
            if( table[str] == 0 ) table[str] = ++id;
            R[table[name]][table[str]]  = true;
            //= R[table[str]][table[name]]
        }
       // print();

        /*
        source = ++id;
        sink = ++id;

        for(int i = 1; i <= N; i++ )
            R[i][sink] = 1;
        for(int x = N+1; x <= N+M; x++ )
            R[source][x] = 1;

        */
        //printf("***** %d %d %d %d\n", N, M, K, id);
        floyd();
      //  print();
        memset(match, -1, sizeof(match));
        int ans = 0;
        for(int i = 0; i < (int)lis.size();i++){
            seen.reset();
            if(matching(lis[i])) ans++;
        }
        printf("%d\n", M - ans);
        if(test)puts("");
    }
    return 0;
}
