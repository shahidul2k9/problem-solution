#include <algorithm>
#include <bitset>

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

typedef pair<int, int > ii;
struct Pair{
    int I;
    int You;
    Pair(){}
    Pair(int I, int Your){
        this->I = I;
        this->You = You;
    }
    /*
    bool operator < (Pair that){
        if( this->I != that.I)
            return this->I < that.I;
        return this->You < that.You;
    }
    */

};
  bool operator < (Pair x, Pair y){
        if(x.I != y.I)
            return x.I < y.I;
        return x.You < y.You;
    }

int main(){
    //freopen("input.txt", "r", stdin);
    int N;
    map<Pair, int> has;
    Pair a, b;
    int exchanged;
    while(scanf("%d", &N) && N){
        exchanged = 0;
        if( N %2 == 0)
            for(int i = 0; i < N; i++){
                scanf("%d %d", &a.I, &a.You);


                b.I = a.You;
                b.You = a.I;

                if(has.find(b) != has.end() && has[b] > 0){
                   has[b] -= 1;
                   exchanged += 1;
                }
                else has[a] += 1;


            }

        else for(int i = 0 ; i < N; i++ )
                scanf("%d %d", &a.I, &a.You);

        if(N %2 == 0 && exchanged == (N >> 1))
            puts("YES");

        else puts("NO");

        has.clear();
    }
    return 0;
}
