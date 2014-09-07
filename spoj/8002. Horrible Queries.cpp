#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long int Type;
#define MAX_ELEMENTS 100000
#define step(x) ((x)& (-x))
 
// Range update Range Query BIT
struct Bit{
    int N;
    Type ft[MAX_ELEMENTS+1];
    //sf[x] contains scaling factor to be subtracted from ft[x]*x to get cumulative sum at index x
    Type sf[MAX_ELEMENTS+1];
 
    Bit(int n): N(n){
        memset(ft, 0, sizeof(Type)*(N+1));
        memset(sf, 0, sizeof(Type)*(N+1));
        }
 
    void init(int n){
        N = n;
        memset(ft, 0, sizeof(Type)*(N+1));
        memset(sf, 0, sizeof(Type)*(N+1));
    }
 
    void add(Type* tree, int idx, Type v){
        while(idx <= N){
            tree[idx] += v;
            idx += step(idx);
        }
    }
    //Returns value at index idx
    Type query(Type* tree, int idx){
        Type s = 0;
        while(idx > 0){
            s += tree[idx];
            idx -= step(idx);
        }
        return s;
    }
    //Returns cumulative sum in rnage [1...idx]
    Type cms(int idx){
         return query(ft, idx)*idx - query(sf,idx);
    }
    Type query(int a, int b){
        return  cms(b) - cms(a-1);
    }
    void update(int a, int b, Type v){
 
        add(ft, a, v);
        add(ft, b+1, -v);
        add(sf, a, v*(a-1));
        add(sf, b+1, -v*b);
    }
};
int main(){
    int op;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int from, to, w,q, n, test;
    Bit bit = Bit(MAX_ELEMENTS);
    scanf("%d", &test);
    while( test-- ){
        scanf("%d %d", &n, &q);
        bit.init(n);
        while(q--){
            scanf("%d", &op);
            if(op){
                scanf("%d %d", &from, &to);
                printf("%lld\n", bit.query(from, to));
            }
            else{
                scanf("%d %d %d", &from, &to, &w);
                bit.update(from, to,w);
            }
        }
    }
	return 0;
}