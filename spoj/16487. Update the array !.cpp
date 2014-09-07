#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long int  Type;
#define MAX_ELEMENTS 100000
#define step(x) ((x)& (-x))

//Range Update Point Query BIT
struct Bit{
    int N;
    Type ft[MAX_ELEMENTS+1];
    Bit(int n):N(n){memset(ft, 0, sizeof(Type)*(N+1));}
    void add(int idx, Type v){
        while(idx <= N){
            ft[idx] += v;
            idx += step(idx);
        }
    }
    void init(int n){
        N = n;
        memset(ft, 0, sizeof(Type)*(N+1));
    }
    //Returns value at index[idx]
    Type query(int idx){
        Type s = 0;
        while(idx > 0){
            s += ft[idx];
            idx -= step(idx);
        }
        return s;
    }
    //Add value v in range [a...b]
    void update(int a, int b, Type v){
        add(a, v);
        add(b+1, -v);
    }

};
int main(){
    //freopen("input.txt", "r", stdin);
    Bit bit = Bit(MAX_ELEMENTS);
    int test, u, n, q, a, b, v;
    scanf("%d", &test);
    while( test-- ){
        scanf("%d %d", &n, &u);
        bit.init(n);
        while(u--){
            scanf("%d %d %d", &a, &b, &v);
            a++;b++;
            if( b < a) swap(a, b);
            bit.update(a, b, v);
        }
        scanf("%d", &q);
        while( q-- ){
            scanf("%d", &a);
            a++;
            printf("%lld\n", bit.query(a));
        }
    }
    return 0;
}
